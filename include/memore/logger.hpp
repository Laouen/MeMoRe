#ifndef MEMORE_LOGGER_HPP
#define MEMORE_LOGGER_HPP

namespace memore {

    template<typename TIME>
    struct coordinator_formatter {

        TIME _current_time;

        static std::string log_info_init(const TIME &t, const std::string &model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:initialization_time,";
            oss << "model:" << model_id << ",";
            oss << "time:" << t;
            oss << "}";
            _current_time = t;
            return oss.str();
        };

        static std::string log_info_collect(const TIME &t, const std::string &model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:collect_time,";
            oss << "model:" << model_id << ",";
            oss << "time:" << t;
            oss << "}";
            _current_time = t;
            return oss.str();
        };

        static std::string log_routing_collect(const std::string &model_id) {
            return "";
        };

        static std::string
        log_info_advance(const TIME &from, const TIME &to, const std::string &model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:advance_simulation_time,";
            oss << "Coordinator for model ";
            oss << "model:" << model_id << ",";
            oss << "from_time:" << from << ",";
            oss << "to_time:" << to << ",";
            oss << "}";
            _current_time = to;
            return oss.str();
        };

        static std::string log_routing_ic_collect(const std::string &model_id) {
            return "";
        };

        static std::string log_routing_eic_collect(const std::string &model_id) {
            return "";
        };
    };

    template <typename TIME>
    struct simulator_formatter {

        TIME _current_time;

        static std::string log_info_init(const TIME& t, const std::string& model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:initialization_time,";
            oss << "model:" << model_id << ",";
            oss << "time:" << t;
            oss << "}";
            _current_time = t;
            return oss.str();
        }

        static std::string log_state(const std::string& model_id, const std::string& model_state) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:state";
            oss << "model:" << model_id << ",";
            oss << "time:" << _current_time<< ",";
            oss << "state:" << model_state;
            oss << "}";
            return oss.str();
        };

        static std::string log_info_collect(const TIME& t, const std::string& model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:collect_time,";
            oss << "model:" << model_id << ",";
            oss << "time:" << t;
            oss << "}";
            _current_time = t;
            return oss.str();
        };

        static std::string log_messages_collect(const std::string& model_id, const std::string& outbox) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:collect_output";
            oss << "model:" << model_id << ",";
            oss << "time:" << _current_time << ",";
            oss << "outbox:" << outbox;
            oss << "}";
            return oss.str();
        };

        static std::string log_info_advance(const TIME& from, const TIME& to, std::string model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:advance_simulation_time,";
            oss << "model:" << model_id << ",";
            oss << "from_time:" << from << ",";
            oss << "to_time:" << to << ",";
            oss << "}";
            _current_time = to;
            return oss.str();
        };

        static std::string log_local_time(const TIME& from, const TIME& to, const std::string& model_id) {
            std::ostringstream oss;
            oss << "{";
            oss << "log:elapsed_time";
            oss << "model:" << model_id << ",";
            oss << "time:" << (to - from);
            oss << "}";
            return oss.str();
        };
    };
}

#endif //MEMORE_LOGGER_HPP
