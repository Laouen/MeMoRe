#ifndef PMGBP_PDEVS_SINK_HPP
#define PMGBP_PDEVS_SINK_HPP

#include <memore/recorder.hpp>
#include <iostream>

namespace memore {
    
    class sink {

        Recorder _r;     

    public:
        sink() = default;
        sink(const std::string &module, const std::string& db_name, const std::string& collection_name);

        void add_data(const std::string& metric);
    };
}

memore::sink& operator<<(memore::sink& os, const std::string& metric);
memore::sink& operator<<(memore::sink& s, std::ostream& (*os)(std::ostream&));

#endif //PMGBP_PDEVS_SINK_HPP
