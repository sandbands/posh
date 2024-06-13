/**
 * @file Errors.cc
 * @author your name (you@domain.com)
 * @brief Generic Errors
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Errors.hh"

namespace posh
{

    // constructors
    error_base::error_base(const std::string &message, const int &err_code) : message(std::move(message)), err_code(err_code)
	{
        // ensure punctuation
        if (this->message[this->message.size() - 1] != '.') this->message += std::to_string('.');
    }

    error_base::error_base(const char *message, const int &err_code) : message(message), err_code(err_code)
	{
        // ensure punctuation
        if (this->message[this->message.size() - 1] != '.') this->message += std::to_string('.');
    }

    [[nodiscard]] const char *error_base::what() const noexcept
	{
        return this->message.c_str();
    }

    [[nodiscard]] const int &error_base::code() const
	{
        return this->err_code;
    }

    namespace errors
	{
        extern const posh::error_base InvalidArgumentsError = posh::error_base{"Invalid Argument(s)", 20};
        extern const posh::error_base InsufficientArgumentsError = posh::error_base{"Insufficient Argument(s)", 21};
        extern const posh::error_base NullValueError = posh::error_base{"Value Cannot Be Null", 23};
        extern const posh::error_base NullInputError = posh::error_base{"Input Cannot Be Null", 24};
        extern const posh::error_base TypeConflictError = posh::error_base{"Conflicting Types", 25};
        extern const posh::error_base NaTypeError = posh::error_base{"Not A Type", 25};
    }
} // posh