#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "posh/posh.hh"
#include "posh/file_helper.hh"
#include "posh/utils.cc"


int main() {
    std::cout << "hello world" << std::endl;
    posh::starts_with("abcdefg", posh::CT_ALPHA , 4);
    return 0;
}

