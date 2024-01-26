//
// Created by Owner on 11/28/2023.
//

#ifndef POSH_UTILS_HH
#define POSH_UTILS_HH

#include <string>
#include <vector>
#include <iostream>
#include "posh.hh"

namespace posh {
    // clear the screen
    static void cls();

    // iterate through each element within substr and check if str begins with it
    static bool starts_with_any_of(const std::string& str, const std::string& substr);

    // check if a string starts with a given substring
    static bool starts_with(const std::string& str, const std::string& substr);

    /*
     * Purpose: check if a string starts with a given character type within the first X characters of 'str'
     *
     * Parameters:
     *      - const std::string& str:
     *          - The std::string Operand
     *      - const CharType& chartype:
     *          = CT_ALPHA      : Letters (abcdefghijklmnopqrstuvwxyzABCDEVGHIJKLMNOPQRSTUVWXYZ)
     *          = CT_SPECIAL    : Miscellaneous characters (~!@#$%^&*()_+`-={}[]|\:;"'<>,.?/)
     *          = CT_INT        : Numbers (positive integers: 0123456789)
     *          = CT_MATH       : Mathematical characters (!%^*-+=/)
     *          = CT_LOGIC      : Logical operator characters (!&|)
     *      - int range:
     *          =   0: standard starts_with operation
     *          >=  1: first (x) characters
     * */
    static bool starts_with(const std::string& str, const CharType& chartype, int range);

    // check if a string starts with a given character
    static bool starts_with(const std::string& str, const char& character);

    // check if a string starts with a given array of doubles, size must be predetermined and specified
    static bool starts_with(const std::string& str, const double doubles[], const int& size);

    // check if a string starts with a given array of floats, size must be predetermined and specified
    static bool starts_with(const std::string& str, const float floats[], const int& size);

    // check if a string starts with a given array of integers, size must be predetermined and specified
    static bool starts_with(const std::string& str, const int ints[], const int& size);

    // check if a string starts with a given array of characters, size must be predetermined and specified
    static bool starts_with(const std::string& str, const char chars[], const int& size);

    // split a string by delimiter and return a vector of substrings
    static std::vector<std::string> split_str(const std::string &str, const std::string &delim);

    // turn a vector into a string
    static std::string vec_to_str(std::vector<std::string>& vec, bool brackets=false);

    // print a vector
    static void print_vec(std::vector<std::string>& vec, bool brackets=false, bool endl=true);

    // return the uppercase version of a string
    static std::string to_upper(const std::string &str);

    // return the lowercase version of a string
    static std::string to_lower(const std::string &str);

    // transform traditional char* argv[] into std::vector<std::string>, must provide argc
    static std::vector<std::string> transform_argv(char* argv[], int& argc);

} // posh namespace


#endif //POSH_UTILS_HH
