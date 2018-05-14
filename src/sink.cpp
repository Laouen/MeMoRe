#include <memore/sink.hpp>

memore::sink::sink(
        const std::string& module,
        const std::string& db_name,
        const std::string& collection_name
) :
        _r(module, db_name, collection_name)
{}

void memore::sink::new_collection(const std::string& collection_name) {
    _r.new_collection(collection_name);
}

void memore::sink::add_data(const std::string& metric) {
	_r.add_data(metric);
}

memore::sink& operator<<(memore::sink& s, const std::string& metric) {
    if (metric != "") {
        s.add_data(metric);
    }
    return s;
}

memore::sink& operator<<(memore::sink& s, std::ostream& (*os)(std::ostream&)) {
    return s;
}