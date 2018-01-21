#ifndef PROJECT_RECORDER_HPP
#define PROJECT_RECORDER_HPP

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include <string>
#include <iostream>
#include <chrono>

namespace memore {
class Recorder {
public:
    Recorder() = default;
    Recorder(const std::string &module, const std::string& db_name, const std::string& collection_name);

    void addData(const std::map<std::string, std::string>& data);
    void addData(const std::string& data);

private:
    unsigned int counter;
    std::string module_name;
    std::string db_name;
    std::string collection_name;
    mongocxx::client connection{};
};
}

#endif //PROJECT_RECORDER_HPP
