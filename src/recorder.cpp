#include <memore/recorder.hpp>
#include <sstream>
#include <iostream>

/****************************************************************************/

using namespace bsoncxx::builder::stream;
using namespace std::chrono;
using bsoncxx::document::value;
using mongocxx::uri;
using mongocxx::client;

memore::Recorder::Recorder(
    const std::string &module,
    const std::string& db_name,
    const std::string& collection_name
) :
    _module_name(module),
    _db_name(db_name),
    _collection_name(collection_name),
    _counter(0),
    _uuid(boost::uuids::random_generator()())
{
    uri uri("mongodb://localhost:27017");
    _connection = client(uri);
}

void memore::newCollection(const std::string& collection_name) {
    _collection_name = collection_name;
}

void memore::Recorder::addData(const std::string& data) {
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    std::ostringstream oss;

    oss << "{";
    oss << "\"uuid\":\"" << boost::uuids::to_string(_uuid) << "\",";
    oss << "\"count\":" << _counter << ",";
    oss << "\"module\":\"" << _module_name << "\",";
    oss << "\"timestamp\":" << std::to_string(ms.count()) << ",";
    oss << "\"data\":" << data;
    oss << "}";

    std::cout << oss.str() << std::endl;

    auto in_doc = bsoncxx::from_json(oss.str());

    auto collection = _connection[_db_name][_collection_name];
    collection.insert_one(in_doc.view());
    _counter++;
}
