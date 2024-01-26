//
// Created by itsrxmmy on 1/10/24.
//

#include "posh.hh"

namespace posh {
    // Thrown when a process, operation, or function, is terminated early
    const char* EarlyTerminationException::what() const noexcept {
        return "Process/Operation Terminated Early.";
    }

    /* // CharTypes
     * typedef enum CharType { } CharType; */

    /* // SizeTypes
     * typedef enum SizeType { } SizeType; */


}
