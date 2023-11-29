//
// Created by Owner on 11/28/2023.
//

#ifndef POSH_UTILS_HH
#define POSH_UTILS_HH

#include <string>
#include <vector>
#include <iostream>

namespace posh {
    // split a string by delimiter and return a vector of substrings
    std::vector<std::string> split_str(const std::string &_str, const std::string &_delim);

    // turn a vector into a string
    std::string vec_to_str(std::vector <std::string> vec);

    // print a vector
    void print_vec(std::vector <std::string> vec);

    // return the uppercase version of a string
    std::string to_upper(const std::string &_str);

    // return the lowercase version of a string
    std::string to_lower(const std::string &_str);
} // posh namespace


#endif //POSH_UTILS_HH
