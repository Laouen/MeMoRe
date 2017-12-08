#include <memore/recorder.hpp>

/**************** unique required and available instance ********************/
mongocxx::instance instance{};
/****************************************************************************/

using namespace std;
using namespace memore;
using namespace bsoncxx::builder::stream;
using namespace std::chrono;
using bsoncxx::document::value;
using mongocxx::uri;
using mongocxx::client;

Recorder::Recorder(const string &module, const string& db_name, const string& collection_name) {
    this->module_name = module;
    this->db_name = db_name;
    this->collection_name = collection_name;
    this->counter = 0;

    uri uri("mongodb://localhost:27017");
    this->connection = client(uri);
}

void Recorder::addData(const map<string, string>& data) {

    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    auto collection = this->connection[this->db_name][this->collection_name];

    document builder{};

    auto in_doc = builder
            << "module" << this->module_name
            << "timestamp" << to_string(ms.count())
            << "data" << open_document;

    for (auto&& e : data) {
        in_doc << e.first << e.second;
    }
    in_doc << close_document;

    value doc = builder << finalize;
    collection.insert_one(builder.view());
}
