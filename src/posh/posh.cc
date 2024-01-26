//
// Created by itsrxmmy on 1/10/24.
//

#include "posh.hh"

namespace posh {
    // Thrown when a process, operation, or function, is terminated early
    const char* early_termination_exception::what() const noexcept {
        return "\n\t--> posh::*::early_termination_exception: Process/Operation Terminated Early.\n";
    }

    /* // CharTypes
     * typedef enum CharType { } CharType; */

    /* // SizeTypes
     * typedef enum SizeType { } SizeType; */


}
