#include <memore/sink.hpp>

memore::sink(
        const std::string &module,
        const std::string& db_name,
        const std::string& collection_name,
        bool console
) :
        _r(module, db_name, collection_name),
        _print_in_console(console)
{}

std::sink& operator<<(std::sink& s, const std::string& metric) {
    _r.addData(metric);
    std::cout << metric;
    return s;
}