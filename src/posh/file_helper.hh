//
// Created by Owner on 11/3/2023.
//

#ifndef POSH_FILE_HELPER_HH
#define POSH_FILE_HELPER_HH

#include <string>
#include <vector>


namespace posh {

    /*
     * File Helper Class
     * Work with files with ease
     * Includes many functions
     */
    class file_helper {
        private:
        // path to file
        std::string path;

        public:
        // constructor
        explicit file_helper(std::string path);

        // get path
        const std::string &get_path();

        // set path
        const std::string &set_path(const std::string &new_path);

        // check if the file exists already, returns false if it does not or if it is a directory
        bool exists();

        // check if a file exists already, returns false if it does not or if it is a directory
        static bool exists(const std::string &path);

        // create the file
        file_helper &create();

        // create a file
        static file_helper create(const std::string &path);

        // delete the file
        bool remove();

        // delete a file
        static bool remove(const std::string &path);

        // read the file and get all the content inside one string
        std::string read();

        // read a file and get all the content inside one string
        static std::string read(const std::string &path);

        // read the file and return a vector of its lines
        std::vector<std::string> read_all();

        // read a file and return a vector of its lines
        static std::vector<std::string> read_all(const std::string &path);

        // read the file and return a vector of specific lines
        std::vector<std::string> read_lines(const std::vector<int> &lines);

        // read a file and return a vector of specific lines
        static std::vector<std::string> read_lines(const std::string &path, const std::vector<int> &lines);

        // read the file and return a specific line
        std::string read_line(const int &line);

        // read a file and return a specific line
        static std::string read_line(const std::string &path, const int &line);

        // erase the file contents
        file_helper &erase();

        // erase a file's contents
        static file_helper erase(const std::string &path);

        // write a line to the file
        file_helper &write(const std::string &line);

        // write a line to a file
        static file_helper write(const std::string &path, const std::string &line);

        // write a line to the file, using the insertion operator
        file_helper &operator<<(const std::string &line);

        // write lines to the file
        file_helper &write(const std::vector<std::string> &lines);

        // write lines to a file
        static file_helper write(const std::string &path, const std::vector<std::string> &lines);

        // write lines to the file, using the insertion operator
        file_helper &operator<<(const std::vector<std::string> &lines);

        // check if the file is currently open
        bool is_open();

        // check if a file is currently open
        static bool is_open(const std::string &path);

        // get the file's size
        int size();

        // get a file's size
        static int size(const std::string &path);

        // create a directory
        static bool mkdir(const std::string &path);

        // remove a directory
        static bool rmdir(const std::string &path);

        // duplicate the file, returns the new file
        file_helper duplicate();

        // duplicate a file, returns the new file
        static file_helper duplicate(const std::string &path);

        // duplicate the file to another location, returns the new file
        file_helper &duplicate_to(const std::string &path2);

        // duplicate a file to another location, returns the new file
        static file_helper duplicate_to(const std::string &path1, const std::string &path2);

        // move the file to a new location
        file_helper &move_to(const std::string &newPath);

        // move a file to a new location
        static file_helper move_to(const std::string &path1, const std::string &path2);

        // rename the file (not recommended for objects, use static method instead)
        file_helper &rename(const std::string &new_name);

        // rename a file
        static file_helper rename(const std::string &path, const std::string &new_name);

        // rewrite the file with one string
        file_helper &rewrite(const std::string &content);

        // rewrite a file with one string
        static file_helper rewrite(const std::string &path, const std::string &content);

        // rewrite a file with multiple lines
        file_helper &rewrite(const std::vector<std::string> &lines);

        // rewrite the file with multiple lines
        static file_helper rewrite(const std::string &path, const std::vector<std::string> &lines);

        // check if the file or directory is empty
        bool is_empty();

        // check if a file or directory is empty
        static bool is_empty(const std::string &path);

        // get the amount of lines the file has
        int lines();

        // get the amount of lines a file has
        static int lines(const std::string &path);

        // append content to the last line of the file
        file_helper &append(const std::string &content);

        // append content to the last line of a file
        static file_helper append(const std::string &path, const std::string &content);

        // append content to the last line of the file
        file_helper &operator+=(const std::string &content);

        // end line
        file_helper &endl();

        // flush
        file_helper &flush();

        // end line
        static file_helper endl(const std::string &path);

        // flush
        static file_helper flush(const std::string &path);

        // truncate the file
        file_helper &trunc();

        // truncate a file
        static file_helper trunc(const std::string &path);

			// General Unknown file_helper Exceptions
		class unknown_exception : public std::exception {
			[[nodiscard]] const char* what() const noexcept override;
		};

		// Thrown when a path is not found
		class path_not_found_exception : public std::exception {
			[[nodiscard]] const char* what() const noexcept override;
		};
    };




} // posh

#endif //POSH_FILE_HELPER_HH
