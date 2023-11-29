cmake_minimum_required(VERSION 3.26)
project(posh)

set(CMAKE_CXX_STANDARD 23)

add_executable(posh posh.cc
        posh/file_helper.cc
        posh/file_helper.hh
        posh/ios/ostream.cc
        posh/ios/ostream.hh
        posh/ios/istream.cc
        posh/ios/istream.hh
        posh/command_engine.cc
        posh/command_engine.hh
        posh.hh
        posh/utils.cc
        posh/utils.hh
)
