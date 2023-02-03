#pragma once

#include <exception>
#include <string>

namespace SFML {
    /**
     * @brief A runtime exception
     */
    class RuntimeException : public std::exception {
    public:
        /**
         * @brief Construct a new Runtime Exception object
         * 
         * @param where The place where the exception was thrown
         * @param error_msg The error message
         */
        RuntimeException(const std::string &where, const std::string &error_msg) : error_msg(where+std::string(": ")+error_msg) {}
        /**
         * @brief Get the error message
         * 
         * @return const char* The error message
         */
        const char *what() const noexcept override {
            return (error_msg.c_str());
        }
    private:
        std::string error_msg;
    };
}