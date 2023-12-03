//
// Created by Owner on 11/30/2023.
//

#ifndef POSH_ERRORS_HH
#define POSH_ERRORS_HH

#include <exception>
#include <string>
#include <utility>

namespace posh {

    class error_base : public std::exception {
        std::string message;
        int err_code;

        public:

        // constructors
        error_base(std::string message, const int &err_code);

        error_base(const char *message, const int &err_code);

        [[nodiscard]] const char *what() const noexcept override;

        [[nodiscard]] const int &code() const;
    };

    namespace errors {
        extern const error_base InvalidArgumentsError;
        extern const error_base InsufficientArgumentsError;
        extern const error_base NullValueError;
        extern const error_base NullInputError;
        extern const error_base TypeConflictError;
        extern const error_base NaTypeError;
    }

} // posh

#endif //POSH_ERRORS_HH
