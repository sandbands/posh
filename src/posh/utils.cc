//
// Created by Owner on 11/28/2023.
//

#include <vector>
#include <string>
#include <iostream>
#include "utils.hh"
#include "posh.hh"

namespace posh {
    // clear the screen
    static void cls() {
        std::system("clear");
    }

    // iterate through each element within substr and check if str begins with it
    static bool starts_with_any_of(const std::string& str, const std::string& substr) {
        for (char c : substr) {
            if (str.starts_with(std::to_string(c))) {
                return true;
            }
        }

        return false;
    }

    // check if a string starts with a given substring
    static bool starts_with(const std::string& str, const std::string& substr) {
        return str.starts_with(substr);
    }

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
    static bool starts_with(const std::string& str, const CharType& chartype, int range) {
        bool single_char = (range == 0);
        bool flag = true;
        for (char charx : str) {
            if (chartype == CT_ALPHA && !starts_with_any_of(std::to_string(charx), "abcdefghijklmnopqrstuvwxyzABCDEVGHIJKLMNOPQRSTUVWXYZ")) {
                return false;
            } else if (chartype == CT_MISC && !starts_with_any_of(std::to_string(charx), "~!@#$%^&*()_+`-={}[]|\\:;\"'<>,.?/")) {
                return false;
            } else if (chartype == CT_INT && !starts_with_any_of(std::to_string(charx), "0123456789")) {
                return false;
            } else if (chartype == CT_MATH && !(starts_with_any_of(std::to_string(charx), "0123456789") || starts_with_any_of(std::to_string(charx), "!%^*-+=/"))) {
                return false;
            } else if (chartype == CT_LOGIC && !(starts_with_any_of(std::to_string(charx), "0123456789") || starts_with_any_of(std::to_string(charx), "!&|"))) {
                return false;
            }

            if (single_char) {
                return true;
            }

            if (range > 0) {
                range--;
                if (range == 0) {
                    break;
                }
            } else {
                break;
            }
        }
        return flag;
    }

    // check if a string starts with a given character
    static bool starts_with(const std::string& str, const char& character) {
        return str.starts_with(character);
    }

    // check if a string starts with a given array of doubles, size must be predetermined and specified
    static bool starts_with(const std::string& str, const double doubles[], const int& size) {
        for (int i=0; i<size; i++) {
            if (str.starts_with(std::to_string(doubles[i]))) {
                return true;
            }
        }

        return false;
    }

    // check if a string starts with a given array of floats, size must be predetermined and specified
    static bool starts_with(const std::string& str, const float floats[], const int& size) {
        for (int i=0; i<size; i++) {
            if (str.starts_with(std::to_string(floats[i]))) {
                return true;
            }
        }

        return false;
    }

    // check if a string starts with a given array of integers, size must be predetermined and specified
    static bool starts_with(const std::string& str, const int ints[], const int& size) {
        for (int i=0; i<size; i++) {
            if (str.starts_with(std::to_string(ints[i]))) {
                return true;
            }
        }

        return false;
    }

    // check if a string starts with a given array of characters, size must be predetermined and specified
    static bool starts_with(const std::string& str, const char chars[], const int& size) {
        for (int i=0; i<size; i++) {
            if (str.starts_with(std::to_string(chars[i]))) {
                return true;
            }
        }

        return false;
    }

    // split a string by delimiter and return a vector of substrings
    static std::vector<std::string> split_str(const std::string& str, const std::string& delim) {
        std::vector<std::string> res;
        std::string token;
        for (int i = 0; i < str.size(); i++) {
            bool flag = true;
            for (int j = 0; j < delim.size(); j++) {
                if (str[i + j] != delim[j]) flag = false;
            }
            if (flag) {
                if (!token.empty()) {
                    res.push_back(token);
                    token = "";
                    i += (int) delim.size() - 1;
                }
            } else {
                token += str[i];
            }
        }
        res.push_back(token);
        return res;
    }

    // turn a vector into a string
    static std::string vec_to_str(std::vector<std::string> vec, bool brackets) {
        std::string result;
        if (brackets) {
            if (!vec.empty()) {
                if (vec.size() > 1) {
                    for (int i = 0; i < vec.size(); i++) {
                        if (i == vec.size() - 1)
                            result += vec[i] + "}";
                        else if (i == 0)
                            result += std::string("{") + vec[i] + ", ";
                        else
                            result += vec[i] + ", ";
                    }
                } else {
                    result += std::string("{") + vec[0] + "}";
                }
            } else {
                result += "{}";
            }
        } else {
            if (!vec.empty()) {
                if (vec.size() > 1) {
                    for (int i=0; i<vec.size(); i++) {
                        if (i == vec.size() - 1)
                            result += vec[i];
                        else
                            result += vec[i] + " ";
                    }
                } else {
                    result += vec[0];
                }
            } else {
                result += "";
            }
        }

        return result;
    }

    // print a vector
    static void print_vec(std::vector<std::string>& vec, bool brackets, bool endl) {
        if (brackets) {
            if (!vec.empty()) {
                if (vec.size() > 1) {
                    for (int i = 0; i < vec.size(); i++) {
                        if (i == vec.size() - 1) {
                            std::cout << vec[i] << "}";
                            if (endl)
                                std::cout << std::endl;
                        }

                        else if (i == 0)
                            std::cout << "{" << vec[i] << ", ";
                        else
                            std::cout << vec[i] << ", ";
                    }
                } else {
                    std::cout << "{" << vec[0] << "}";
                    if (endl)
                        std::cout << std::endl;
                }
            } else {
                std::cout << "{}";
                if (endl)
                    std::cout << std::endl;
            }
        } else {
            if (!vec.empty()) {
                if (vec.size() > 1) {
                    for (int i = 0; i < vec.size(); i++) {
                        if (i == vec.size() - 1) {
                            std::cout << vec[i];
                            if (endl)
                                std::cout << std::endl;
                        }
                        else
                            std::cout << vec[i] << " ";
                    }
                } else {
                    std::cout << vec[0];
                    if (endl)
                        std::cout << std::endl;
                }
            } else {
                std::cout << "";
                if (endl)
                    std::cout << std::endl;
            }
        }
    }

    // return the uppercase version of a string
    static std::string to_upper(const std::string& str) {
        std::string result;
        for (char c : str) {
            switch (c) {
                case 'a':
                    result += 'A';
                    break;
                case 'b':
                    result += 'B';
                case 'c':
                    result += 'C';
                    break;
                case 'd':
                    result += 'D';
                    break;
                case 'e':
                    result += 'E';
                    break;
                case 'f':
                    result += 'F';
                    break;
                case 'g':
                    result += 'G';
                    break;
                case 'h':
                    result += 'H';
                    break;
                case 'i':
                    result += 'I';
                    break;
                case 'j':
                    result += 'J';
                    break;
                case 'k':
                    result += 'K';
                    break;
                case 'l':
                    result += 'L';
                    break;
                case 'm':
                    result += 'M';
                    break;
                case 'n':
                    result += 'N';
                    break;
                case 'o':
                    result += 'O';
                    break;
                case 'p':
                    result += 'P';
                    break;
                case 'q':
                    result += 'Q';
                    break;
                case 'r':
                    result += 'R';
                    break;
                case 's':
                    result += 'S';
                    break;
                case 't':
                    result += 'T';
                    break;
                case 'u':
                    result += 'U';
                    break;
                case 'v':
                    result += 'V';
                    break;
                case 'w':
                    result += 'W';
                    break;
                case 'x':
                    result += 'X';
                    break;
                case 'y':
                    result += 'Y';
                    break;
                case 'z':
                    result += 'Z';
                    break;
                default:
                    result += c;
                    break;
            }
        }
        return result;
    }

    // return the lowercase version of a string
    static std::string to_lower(const std::string& str) {
        std::string result;
        for (char c : str) {
            switch (c) {
                case 'A':
                    result += 'a';
                    break;
                case 'B':
                    result += 'b';
                case 'C':
                    result += 'c';
                    break;
                case 'D':
                    result += 'd';
                    break;
                case 'E':
                    result += 'e';
                    break;
                case 'F':
                    result += 'f';
                    break;
                case 'G':
                    result += 'g';
                    break;
                case 'H':
                    result += 'h';
                    break;
                case 'I':
                    result += 'i';
                    break;
                case 'J':
                    result += 'j';
                    break;
                case 'K':
                    result += 'k';
                    break;
                case 'L':
                    result += 'l';
                    break;
                case 'M':
                    result += 'm';
                    break;
                case 'N':
                    result += 'n';
                    break;
                case 'O':
                    result += 'o';
                    break;
                case 'P':
                    result += 'p';
                    break;
                case 'Q':
                    result += 'q';
                    break;
                case 'R':
                    result += 'r';
                    break;
                case 'S':
                    result += 's';
                    break;
                case 'T':
                    result += 't';
                    break;
                case 'U':
                    result += 'u';
                    break;
                case 'V':
                    result += 'v';
                    break;
                case 'W':
                    result += 'w';
                    break;
                case 'X':
                    result += 'x';
                    break;
                case 'Y':
                    result += 'y';
                    break;
                case 'Z':
                    result += 'z';
                    break;
                default:
                    result += c;
                    break;
            }
        }
        return result;
    }

    // transform traditional char* argv[] into std::vector<std::string>, must provide argc
    static std::vector<std::string> transform_argv(char* argv[], int& argc) {

        std::vector<std::string> result;

        if (argc == 1)
            return result;

        for (int i=0; i<argc; i++)
            result.emplace_back(argv[i]);

        return result;
    }


} // posh

