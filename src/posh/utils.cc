//
// Created by Owner on 11/28/2023.
//

#include "utils.hh"
#include <vector>
#include <string>
#include <iostream>

namespace posh {
    // split a string by delimiter and return a vector of substrings
    // won't bother adding documentation here because I copied this code lol
    std::vector <std::string> split_str(const std::string &_str, const std::string &_delim) {
        std::vector <std::string> res;
        std::string token;
        for (int i = 0; i < _str.size(); i++) {
            bool flag = true;
            for (int j = 0; j < _delim.size(); j++) {
                if (_str[i + j] != _delim[j]) flag = false;
            }
            if (flag) {
                if (!token.empty()) {
                    res.push_back(token);
                    token = "";
                    i += (int) _delim.size() - 1;
                }
            } else {
                token += _str[i];
            }
        }
        res.push_back(token);
        return res;
    }

    // turn a vector into a string
    std::string vec_to_str(std::vector <std::string> vec) {
        std::string result;
        if (!vec.empty()) { // make sure the vector isn't empty
            if (vec.size() > 1) { // check if it has more than 1 element
                for (int i = 0; i < vec.size(); i++) {
                    if (i == vec.size() - 1) // if it's the last element, end with a closing bracket instead of ", "
                        result += vec[i] += "}";
                    else if (i == 0)
                        result += std::string("{") += vec[i] += ", "; // if it's the first element, start with a starting bracket and end with ", "
                    else
                        result += vec[i] += ", "; // for every other item, end with ", "
                }
            } else { // if there is only one element, place it in between a pair of brackets
                result += std::string("{") += vec[0] += "}";
            }
        } else { // if it's empty, return an empty pair of brackets
            result += "{}";
        }

        return result;
    }

    // print a vector
    void print_vec(std::vector <std::string> vec) {
        if (!vec.empty()) {
            if (vec.size() > 1) {
                for (int i = 0; i < vec.size(); i++) {
                    if (i == vec.size() - 1)
                        std::cout << vec[i] << "}" << std::endl;
                    else if (i == 0)
                        std::cout << "{" << vec[i] << ", ";
                    else
                        std::cout << vec[i] << ", ";
                }
            } else {
                std::cout << "{" << vec[0] << "}" << std::endl;
            }
        } else {
            std::cout << "{}" << std::endl;
        }
    }

    // return the uppercase version of a string
    std::string to_upper(const std::string &_str) {
        std::string result;
        // iterate through each character and if it's lowercase then apply the uppercase version
        // to the result string, otherwise apply it anyway
        for (char c: _str) {
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
    std::string to_lower(const std::string &_str) {
        std::string result;
        // iterate through each character and if it's uppercase then apply the lowercase version
        // to the result string, otherwise apply it anyway
        for (char c: _str) {
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
} // posh