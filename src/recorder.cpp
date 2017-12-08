#include <memore/recorder.hpp>

/**************** unique required and available instance ********************/
mongocxx::instance instance{};
/****************************************************************************/

Recorder::Recorder(const std::string &module, const std::string& db_name, const std::string& collection_name) {
    this->module_name = module;
    this->db_name = db_name;
    this->collection_name = collection_name;
    this->counter = 0;
    mongocxx::uri uri("mongodb://localhost:27017");
    this->connection = mongocxx::client(uri);
}

void Recorder::addData(const std::map<std::string, std::string>& data) {

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    auto collection = this->connection[this->db_name][this->collection_name];

    bsoncxx::builder::stream::document builder{};

    auto in_doc = builder
            << "module" << this->module_name
            << "timestamp" << std::to_string(ms.count())
            << "data" << bsoncxx::builder::stream::open_document;

    for (auto&& e : data) {
        in_doc << e.first << e.second;
    }
    in_doc << bsoncxx::builder::stream::close_document;

    bsoncxx::document::value doc = builder << bsoncxx::builder::stream::finalize;

    collection.insert_one(builder.view());
}
