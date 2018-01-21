#include <memore/recorder.hpp>
#include <sstream>

/**************** unique required and available instance ********************/
mongocxx::instance instance{};
/****************************************************************************/

using namespace bsoncxx::builder::stream;
using namespace std::chrono;
using bsoncxx::document::value;
using mongocxx::uri;
using mongocxx::client;

memore::Recorder::Recorder(const std::string &module, const std::string& db_name, const std::string& collection_name) {
    this->module_name = module;
    this->db_name = db_name;
    this->collection_name = collection_name;
    this->counter = 0;

    uri uri("mongodb://localhost:27017");
    this->connection = client(uri);
}

void memore::Recorder::addData(const std::string& data) {
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    std::ostringstream oss;

    oss << "{";
    oss << "\"count\":\"" << this->counter << "\",";
    oss << "\"module\":\"" << this->module_name << "\",";
    oss << "\"timestamp\":\"" << std::to_string(ms.count()) << "\",";
    oss << "\"data\":" << data;
    oss << "}";

    auto in_doc = bsoncxx::from_json(oss.str());

    auto collection = this->connection[this->db_name][this->collection_name];
    collection.insert_one(in_doc.view());
    this->counter++;
}
