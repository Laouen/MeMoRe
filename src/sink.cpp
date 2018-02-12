#include <memore/sink.hpp>

memore::sink(
        const std::string& module,
        const std::string& db_name,
        const std::string& collection_name
) :
        _r(module, db_name, collection_name)
{}

std::sink& operator<<(std::sink& s, const std::string& metric) {
    if (metric != "") {
        _r.addData(metric);
        std::cout << metric;
    }
    return s;
}