#include <memore/recorder.hpp>

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

void memore::Recorder::addData(const std::map<std::string, std::string>& data) {

    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    auto collection = this->connection[this->db_name][this->collection_name];

    document builder{};

    auto in_doc = builder
            << "count" << this->counter;
            << "module" << this->module_name
            << "timestamp" << std::to_string(ms.count())
            << "data" << open_document;

    for (auto&& e : data) {
        in_doc << e.first << e.second;
    }
    in_doc << close_document;

    value doc = builder << finalize;
    collection.insert_one(builder.view());
    this->counter++;
}

void addData(const std::string& data) {
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    std::ostringstream oss;

    oss << "{";
    oss << "\"count\":\"" << this->counter << "\",";
    oss << "\"module\":\"" << this->module_name << "\",";
    oss << "\"timestamp\":\"" << std::to_string(ms.count()) << "\",";
    oss << "\"data\":\"" << data;
    oss << "}";
    bsoncxx::from_json =  oss.str();

    auto collection = this->connection[this->db_name][this->collection_name];
    collection.insert_one(builder.view());
    this->counter++;
}
