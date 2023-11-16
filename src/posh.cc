#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "posh.hh"
#include "posh/file_helper.hh"



int main() {
    posh::file_helper file("./testfile.txt");
    file.trunc();
    file.write("hello").write("world").append("!").flush().write("\t\t\t\t\t\t").flush().write("test");
}


