#include <memore/sink.hpp>

memore::sink::sink(
        const std::string& module,
        const std::string& db_name,
        const std::string& collection_name
) :
        _r(module, db_name, collection_name)
{}

void memore::sink::add_data(const std::string& metric) {
	_r.addData(metric);
}

memore::sink& operator<<(memore::sink& s, const std::string& metric) {
    if (metric != "") {
        s.add_data(metric);
        std::cout << metric;
    }
    return s;
}