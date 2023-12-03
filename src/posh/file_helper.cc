//
// Created by Owner on 11/3/2023.
//

#include <fstream>
#include <filesystem>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include "file_helper.hh"

namespace posh {
    /**
     * Define the File Helper Class
     */

    // file helper constructor
    file_helper::file_helper(std::string path) : path(std::move(path)) {}

    // get path
    const std::string &file_helper::get_path() {
        return this->path;
    }

    // set path
    const std::string &file_helper::set_path(const std::string &new_path) {
        this->path = new_path;
        return this->path;
    }

    // check if the file exists already, returns false if it does not or if it is a directory
    bool file_helper::exists() {
        return std::filesystem::exists(this->path) && !(std::filesystem::is_directory(this->path));
    }

    // check if a file exists already, returns false if it does not or if it is a directory
    bool file_helper::exists(const std::string &path) {
        return std::filesystem::exists(path) && !(std::filesystem::is_directory(path));
    }

    // create the file
    file_helper &file_helper::create() {
        std::fstream file;
        file.open(this->path, std::ios::out);
        file.close();
        return *this;
    }

    // create a file
    file_helper file_helper::create(const std::string &path) {
        std::fstream file;
        file.open(path, std::ios::out);
        file.close();
        return file_helper(path);
    }

    // delete the file
    bool file_helper::remove() {
        return std::filesystem::remove(this->path);
    }

    // delete a file
    bool file_helper::remove(const std::string &path) {
        return std::filesystem::remove(path);
    }

    // read the file and get all the content inside one string
    std::string file_helper::read() {
        std::vector<std::string> lines = file_helper::read_all();
        std::string content;

        for (int i = 0; i < (int) lines.size(); i++) {
            // don't add another newline character if it's the last line
            if (i == (int) lines.size() - 1) {
                content += lines[i];
            }

                // otherwise, add a newline
            else {
                content += lines[i] + "\n";
            }
        }

        return content;
    }

    // read a file and get all the content inside one string
    std::string file_helper::read(const std::string &path) {
        std::vector<std::string> lines = file_helper::read_all(path);
        std::string content;

        for (int i = 0; i < (int) lines.size(); i++) {
            // don't add another newline character if it's the last line
            if (i == (int) lines.size() - 1) {
                content += lines[i];
            }

                // otherwise, add a newline
            else {
                content += lines[i] + "\n";
            }
        }

        return content;
    }

    // read the file and return a vector of its lines
    std::vector<std::string> file_helper::read_all() {
        std::vector<std::string> content;

        std::fstream file;
        file.open(this->path);

        for (std::string line; std::getline(file, line);)
            content.push_back(line);

        file.close();

        return content;
    }

    // read a file and return a vector of its lines
    std::vector<std::string> file_helper::read_all(const std::string &path) {
        std::vector<std::string> content;

        std::fstream file;
        file.open(path);

        for (std::string line; std::getline(file, line);)
            content.push_back(line);

        file.close();

        return content;
    }

    // read the file and return a vector of specific lines
    std::vector<std::string> file_helper::read_lines(const std::vector<int> &lines) {
        std::vector<std::string> result, all_lines;
        all_lines = this->read_all();

        for (int i = 0; i < (int) all_lines.size(); i++) {
            for (int j = 0; j < (int) lines.size(); j++) {
                if (i == j)
                    result.push_back(all_lines[i]);
            }
        }

        return result;
    }

    // read a file and return a vector of specific lines
    std::vector<std::string> file_helper::read_lines(const std::string &path, const std::vector<int> &lines) {
        std::vector<std::string> result, all_lines;
        all_lines = file_helper::read_all(path);

        for (int i = 0; i < (int) all_lines.size(); i++) {
            for (int j = 0; j < (int) lines.size(); j++) {
                if (i == j)
                    result.push_back(all_lines[i]);
            }
        }

        return result;
    }

    // read the file and return a specific line
    std::string file_helper::read_line(const int &line) {
        std::vector<std::string> lines;
        lines = this->read_all(this->path);

        for (int i = 0; i < (int) lines.size(); i++) {
            if (i == line)
                return lines[line];
        }

        return "";
    }

    // read a file and return a specific line
    std::string file_helper::read_line(const std::string &path, const int &line) {
        std::vector<std::string> lines;
        lines = file_helper::read_all(path);

        for (int i = 0; i < (int) lines.size(); i++) {
            if (i == line)
                return lines[line];
        }

        return "";
    }

    // erase the file contents
    file_helper &file_helper::erase() {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::trunc); // open in trunc mode
        file.close();
        return *this;
    }

    // erase a file's contents
    file_helper file_helper::erase(const std::string &path) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::trunc); // open in trunc mode
        file.close();
        return file_helper(path);
    }

    // write a line to the file
    file_helper &file_helper::write(const std::string &line) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode

        // if it's the first line, then don't add a newline character
        if (this->read_all().empty()) {
            file << line;
        }

            // otherwise, add the content to a new line
        else {
            file << "\n" << line;
        }

        file.close();
        return *this;
    }

    // write a line to a file
    file_helper file_helper::write(const std::string &path, const std::string &line) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::app); // open in append mode

        // if it's the first line, then don't add a newline character
        if (file_helper::read_all(path).empty()) {
            file << line;
        }

            // otherwise, add the content to a new line
        else {
            file << "\n" << line;
        }

        file.close();
        return file_helper(path);
    }

    // write a line to the file, using the insertion operator
    file_helper &file_helper::operator<<(const std::string &line) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode

        // if it's the first line, then don't add a newline character
        if (this->read_all().empty()) {
            file << line;
        }

            // otherwise, add the content to a new line
        else {
            file << "\n" << line;
        }

        file.close();
        return *this;
    }

    // write lines to the file
    file_helper &file_helper::write(const std::vector<std::string> &lines) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode

        if (lines.empty()) {
            // if it's the first line, then don't add a newline character
            if (this->read_all().empty()) {
                file << lines[0];
            }
        }

        // don't attempt the next loop which starts at index 1 if there is only 1 item
        if (lines.size() < 2)
            return *this;

        for (int i = 1; i < (int) lines.size(); i++) {
            // only end if it's not the last line
            if (i != (int) lines.size() - 1)
                file << lines[i] << std::endl;

                // otherwise don't end it
            else
                file << lines[i];
        }

        file.close();
        return *this;
    }

    // write lines to a file
    file_helper file_helper::write(const std::string &path, const std::vector<std::string> &lines) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::app); // open in append mode

        if (lines.empty()) {
            // if it's the first line, then don't add a newline character
            if (file_helper::read_all(path).empty()) {
                file << lines[0];
            }
        }

        // don't attempt the next loop which starts at index 1 if there is only 1 item
        if (lines.size() < 2)
            return file_helper(path);

        for (int i = 1; i < (int) lines.size(); i++) {
            // only end if it's not the last line
            if (i != (int) lines.size() - 1)
                file << lines[i] << std::endl;

                // otherwise don't end it
            else
                file << lines[i];
        }

        file.close();
        return file_helper(path);
    }

    // write lines to the file, using the insertion operator
    file_helper &file_helper::operator<<(const std::vector<std::string> &lines) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode

        if (lines.empty()) {
            // if it's the first line, then don't add a newline character
            if (this->read_all().empty()) {
                file << lines[0];
            }
        }

        // don't attempt the next loop which starts at index 1 if there is only 1 item
        if (lines.size() < 2)
            return *this;

        for (int i = 1; i < (int) lines.size(); i++) {
            // only end if it's not the last line
            if (i != (int) lines.size() - 1)
                file << lines[i] << std::endl;

                // otherwise don't end it
            else
                file << lines[i];
        }

        file.close();
        return *this;
    }

    // check if the file is currently open
    bool file_helper::is_open() {
        std::fstream file(this->path);
        return file.is_open();
    }

    // check if a file is currently open
    bool file_helper::is_open(const std::string &path) {
        std::fstream file(path);
        return file.is_open();
    }

    // get the file's size
    int file_helper::size() {
        return (int) std::filesystem::file_size(this->path);
    }

    // get a file's size
    int file_helper::size(const std::string &path) {
        return (int) std::filesystem::file_size(path);
    }

    // create a directory
    bool file_helper::mkdir(const std::string &path) {
        return std::filesystem::create_directory(path);
    }

    // remove a directory
    bool file_helper::rmdir(const std::string &path) {
        return std::filesystem::remove_all(path);
    }

    // duplicate the file, returns the new file
    file_helper file_helper::duplicate() {
        std::string new_path = this->path;
        std::string ext = std::filesystem::path(this->path).extension().string();

        // get the length of file extension so that we know how much to trim off
        int ext_length = (int) ext.size();

        // fill the new_path string with the contents of this->path, excluding the file extension
        for (int i = 0; i < (int) this->path.size() - ext_length; i++)
            new_path += this->path[i];

        // check for other duplicates and increment the number
        for (int i = 1;; i++) {
            if (std::filesystem::exists((new_path + "-" + std::to_string(i))))
                continue;
            else {
                new_path += ("-" + std::to_string(i) + ext);
                break;
            }
        }

        return file_helper(new_path);
    }

    // duplicate a file, returns the new file
    file_helper file_helper::duplicate(const std::string &path) {
        std::string new_path = path;
        std::string ext = std::filesystem::path(path).extension().string();

        // get the length of file extension so that we know how much to trim off
        int ext_length = (int) ext.size();

        // fill the new_path string with the contents of path, excluding the file extension
        for (int i = 0; i < (int) path.size() - ext_length; i++)
            new_path += path[i];

        // check for other duplicates and increment the number
        for (int i = 1;; i++) {
            if (std::filesystem::exists((new_path + "-" + std::to_string(i))))
                continue;
            else {
                new_path += ("-" + std::to_string(i) + ext);
                break;
            }
        }

        return file_helper(new_path);
    }

    // duplicate the file to another location, returns the new file
    file_helper &file_helper::duplicate_to(const std::string &path2) {
        std::filesystem::copy_file(this->path, path2);
        return *this;
    }

    // duplicate a file to another location, returns the new file
    file_helper file_helper::duplicate_to(const std::string &path1, const std::string &path2) {
        std::filesystem::copy_file(path1, path2);
        return file_helper(path2);
    }

    // move the file to a new location
    file_helper &file_helper::move_to(const std::string &new_path) {
        this->duplicate_to(new_path);
        this->remove();
        this->set_path(new_path);
        return *this;
    }

    // move a file to a new location
    file_helper file_helper::move_to(const std::string &path1, const std::string &path2) {
        file_helper::duplicate_to(path1, path2);
        file_helper::remove(path1);
        return file_helper(path2);
    }

    // rename the file (not recommended for objects, use static method instead)
    file_helper &file_helper::rename(const std::string &new_name) {
        std::rename(this->path.c_str(), new_name.c_str());
        this->path = new_name;
        return *this;
    }

    // rename a file
    file_helper file_helper::rename(const std::string &path, const std::string &new_name) {
        std::rename(path.c_str(), new_name.c_str());
        return file_helper(new_name);
    }

    // rewrite the file with one string
    file_helper &file_helper::rewrite(const std::string &content) {
        this->erase();
        return this->write(content);
    }

    // rewrite a file with one string
    file_helper file_helper::rewrite(const std::string &path, const std::string &content) {
        file_helper::erase(path);
        return file_helper::write(path, content);
    }

    // rewrite a file with multiple lines
    file_helper &file_helper::rewrite(const std::vector<std::string> &lines) {
        this->erase();
        return this->write(lines);
    }

    // rewrite the file with multiple lines
    file_helper file_helper::rewrite(const std::string &path, const std::vector<std::string> &lines) {
        file_helper::erase(path);
        return file_helper::write(path, lines);
    }

    // check if the file or directory is empty
    bool file_helper::is_empty() {
        return std::filesystem::is_empty(this->path);
    }

    // check if a file or directory is empty
    bool file_helper::is_empty(const std::string &path) {
        return std::filesystem::is_empty(path);
    }

    // get the amount of lines the file has
    int file_helper::lines() {
        return (int) file_helper::read_all().size();
    }

    // get the amount of lines a file has
    int file_helper::lines(const std::string &path) {
        return (int) file_helper::read_all(path).size();
    }

    // append content to the last line of the file
    file_helper &file_helper::append(const std::string &content) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode
        file << content;
        file.close();
        return *this;
    }

    // append content to the last line of a file
    file_helper file_helper::append(const std::string &path, const std::string &content) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::app); // open in append mode
        file << content;
        file.close();
        return file_helper(path);
    }

    // append content to the last line of the file
    file_helper &file_helper::operator+=(const std::string &content) {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode
        file << content;
        file.close();
        return *this;
    }

    // end line
    file_helper &file_helper::endl() {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode
        file << std::endl;
        file.close();
        return *this;
    }

    // flush
    file_helper &file_helper::flush() {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::app); // open in append mode
        file.flush();
        file.close();
        return *this;
    }

    // end line
    file_helper file_helper::endl(const std::string &path) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::app); // open in append mode
        file << std::endl;
        file.close();
        return file_helper(path);
    }

    // flush the file
    file_helper file_helper::flush(const std::string &path) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::app); // open in append mode
        file.flush();
        file.close();
        return file_helper(path);
    }

    // truncate the file
    file_helper &file_helper::trunc() {
        std::fstream file;
        file.open(this->path, std::ios::out | std::ios::trunc); // open in truncate mode
        file.close();
        return *this;
    }

    // truncate a file
    file_helper file_helper::trunc(const std::string &path) {
        std::fstream file;
        file.open(path, std::ios::out | std::ios::trunc); // open in truncate mode
        file.close();
        return file_helper(path);
    }
}
