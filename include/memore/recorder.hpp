#ifndef PROJECT_RECORDER_HPP
#define PROJECT_RECORDER_HPP

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/core.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <string>
#include <iostream>
#include <chrono>

namespace memore {
    class Recorder {
    public:
        Recorder() = default;
        Recorder(const std::string &module, const std::string& db_name, const std::string& collection_name);

        void newCollection(const std::string& collection_name);
        void addData(const std::string& data);

    private:
        boost::uuids::uuid _uuid;
        unsigned int _counter;
        std::string _module_name;
        std::string _db_name;
        std::string _collection_name;
        mongocxx::client _connection{};
    };
}

#endif //PROJECT_RECORDER_HPP
