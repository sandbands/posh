/**
 * @file errors.hh
 * @author your name (you@domain.com)
 * @brief Generic Errors
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef POSH_ERRORS_HH
#define POSH_ERRORS_HH

#include <exception>
#include <string>
#include <utility>

namespace posh
{

    class error_base : public std::exception
	{
		private:
        std::string message;
        int err_code;

        public:

        // constructors
        error_base(const std::string &message, const int err_code);

        error_base(const char *message, const int err_code);

        [[nodiscard]] const char *what() const noexcept override;

        [[nodiscard]] const int code() const;
    };

    namespace errors
	{
        extern const posh::error_base ErrorInvalidArguments;
        extern const posh::error_base ErrorInsufficientArguments;
        extern const posh::error_base ErrorTooManyArguments;
        extern const posh::error_base ErrorNullValue;
        extern const posh::error_base ErrorNullInput;
        extern const posh::error_base ErrorTypeConflict;
        extern const posh::error_base ErrorNotAType;
        extern const posh::error_base ErrorNotAPath;
        extern const posh::error_base ErrorNotAFile;
        extern const posh::error_base ErrorNotADirectory;
    }

} // posh

#endif // POSH_ERRORS_HH
