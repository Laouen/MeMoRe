#ifndef MEMORE_LOGGER_HPP
#define MEMORE_LOGGER_HPP

namespace memore {
    namespace logger {
        template<typename TIME>
        struct formatter {

            static std::string coor_info_init(const TIME &t, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"initialization_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_info_collect(const TIME &t, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"collect_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_routing_eoc_collect(const TIME &t, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"EOC\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_info_advance(const TIME &from, const TIME &to, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"advance_simulation_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"from_time\":\"" << from << "\",";
                oss << "\"to_time\":\"" << to << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_routing_ic_collect(const TIME &t, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"IC\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_routing_eic_collect(const TIME &t, const std::string &model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"EIC\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string coor_routing_collect(const std::string& from_port, const std::string& to_port, const std::vector<std::string>& from_messages, const std::vector<std::string>& to_messages) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"routing_collect\",";
                oss << "\"from_port\":\"" << from_port << "\",";
                oss << "\"to_port\":\"" << to_port << "\",";
                oss << "\"from_messages\": [";
                for (const auto& m : from_messages) {
                    oss << m;
                    if (m != from_messages.back()) {
                        oss << ",";
                    }
                } 
                oss << "]";
                oss << "\"to_messages\": [";
                for (const auto& m : to_messages) {
                    oss << m;
                    if (m != to_messages.back()) {
                        oss << ",";
                    }
                } 
                oss << "]";
                oss << "}";
                return oss.str();
            }

            static std::string sim_info_init(const TIME& t, const std::string& model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"initialization_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            }

            static std::string sim_state(const TIME &t, const std::string& model_id, const std::string& model_state) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"state\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"state\":" << model_state << ",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string sim_info_collect(const TIME& t, const std::string& model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"collect_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string sim_messages_collect(const TIME &t, const std::string& model_id, const std::string& outbox) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"collect_output\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"time\":\"" << t << "\"";
                //oss << "\"outbox\":\"" << outbox << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string sim_info_advance(const TIME& from, const TIME& to, std::string model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"advance_simulation_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"from_time\":\"" << from << "\",";
                oss << "\"to_time\":\"" << to << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string sim_local_time(const TIME& from, const TIME& to, const std::string& model_id) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"elapsed_time\",";
                oss << "\"model\":\"" << model_id << "\",";
                oss << "\"elapsed\":\"" << (to - from)  << "\",";
                oss << "\"time\":\"" << to << "\"";
                oss << "}";
                return oss.str();
            };

            static std::string run_global_time(const TIME& global_time) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"global_time\",";
                oss << "\"time\":\"" << global_time << "\"";
                oss << "}";
                return oss.str();
            }

            static std::string run_info(const std::string& message) {
                std::ostringstream oss;
                oss << "{";
                oss << "\"log\":\"information\",";
                oss << "\"message\":\"" << message << "\"";
                oss << "}";
                return oss.str();
            }
        };
    }
}
#endif //MEMORE_LOGGER_HPP
