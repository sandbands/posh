/**
 * @file posh.cc
 * @author your name (you@domain.com)
 * @brief posh Library
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "posh.hh"

namespace posh
{
    // Thrown when a process, operation, or function, is terminated early
    const char* early_termination_exception::what() const noexcept
	{
        return "\n[posh::*::early_termination_exception] Process/Operation Terminated Early.\n";
    }

    /* // CharTypes
     * typedef enum CharType { } CharType; */

    /* // SizeTypes
     * typedef enum SizeType { } SizeType; */


}


