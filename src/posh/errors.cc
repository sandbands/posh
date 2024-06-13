/**
 * @file errors.cc
 * @author your name (you@domain.com)
 * @brief Generic Errors
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "errors.hh"

namespace posh
{

    // constructors
    error_base::error_base(const std::string &message, const int err_code)
	{
		this->message = message;
		this->err_code = err_code;
    
	    // ensure punctuation
        if (this->message[this->message.size() - 1] != '.') this->message += std::to_string('.');
    }

    error_base::error_base(const char *message, const int err_code)
	{
		this->message = std::string(message);
		this->err_code = err_code;

        // ensure punctuation
        if (this->message[this->message.size() - 1] != '.') this->message += std::to_string('.');
    }

    [[nodiscard]] const char *error_base::what() const noexcept
	{
        return this->message.c_str();
    }

    [[nodiscard]] const int error_base::code() const
	{
        return this->err_code;
    }

    namespace errors
	{
        extern const posh::error_base ErrorInvalidArguments = posh::error_base{"Invalid Argument(s) Found", 20};
        extern const posh::error_base ErrorInsufficientArguments = posh::error_base{"Insufficient Argument(s)", 21};
        extern const posh::error_base ErrorTooManyArguments = posh::error_base{"Too Many Arguments Found", 22};
        extern const posh::error_base ErrorNullValue = posh::error_base{"Value Cannot Be Null", 23};
        extern const posh::error_base ErrorNullInput = posh::error_base{"Input Cannot Be Null", 24};
        extern const posh::error_base ErrorTypeConflict = posh::error_base{"Conflicting Types", 25};
        extern const posh::error_base ErrorNotAType = posh::error_base{"Not A Type", 26};
        extern const posh::error_base ErrorNotAPath = posh::error_base{"Path Does Not Exist On This System", 27};
        extern const posh::error_base ErrorNotAFile = posh::error_base{"Path Is Not A File", 28};
        extern const posh::error_base ErrorNotADirectory = posh::error_base{"Path Is Not A Directory", 29};
    }
} // posh