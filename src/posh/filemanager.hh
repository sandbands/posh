/**
 * @file filemanager.hh
 * @author your name (you@domain.com)
 * @brief File Management
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef POSH_FILEMANAGER_HH
#define POSH_FILEMANAGER_HH

#include <string>
#include <vector>
#include <filesystem>


namespace posh
{

    /*
     * File Helper Class
     * Work with files with ease
     * Includes many functions
     */
    class filemanager
	{
        private:
        // path to file
        std::string path;

        public:
        // constructor
        explicit filemanager(const std::string &path);

        // constructor
        explicit filemanager(const char *path);

        // get path
        const std::string &get_path();

        // set path
        const std::string &set_path(const std::string &new_path);

        // check if the file exists already, returns false if it does not or if it is a directory
        bool exists();

        // check if a file exists already, returns false if it does not or if it is a directory
        static bool exists(const std::string &path);

        // create the file
        filemanager &create();

        // create a file
        static filemanager create(const std::string &path);

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
        std::string read_line(const int line);

        // read a file and return a specific line
        static std::string read_line(const std::string &path, const int line);

        // erase the file contents
        filemanager &erase();

        // erase a file's contents
        static filemanager erase(const std::string &path);

        // write a line to the file
        filemanager &write(const std::string &line);

        // write a line to a file
        static filemanager write(const std::string &path, const std::string &line);

        // write a line to the file, using the insertion operator
        filemanager &operator<<(const std::string &line);

        // write lines to the file
        filemanager &write(const std::vector<std::string> &lines);

        // write lines to a file
        static filemanager write(const std::string &path, const std::vector<std::string> &lines);

        // write lines to the file, using the insertion operator
        filemanager &operator<<(const std::vector<std::string> &lines);

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
        filemanager duplicate();

        // duplicate a file, returns the new file
        static filemanager duplicate(const std::string &path);

        // duplicate the file to another location, returns the new file
        filemanager &duplicate_to(const std::string &path2);

        // duplicate a file to another location, returns the new file
        static filemanager duplicate_to(const std::string &path1, const std::string &path2);

        // move the file to a new location
        filemanager &move_to(const std::string &newPath);

        // move a file to a new location
        static filemanager move_to(const std::string &path1, const std::string &path2);

        // rename the file (not recommended for objects, use static method instead)
        filemanager &rename(const std::string &new_name);

        // rename a file
        static filemanager rename(const std::string &path, const std::string &new_name);

        // rewrite the file with one string
        filemanager &rewrite(const std::string &content);

        // rewrite a file with one string
        static filemanager rewrite(const std::string &path, const std::string &content);

        // rewrite a file with multiple lines
        filemanager &rewrite(const std::vector<std::string> &lines);

        // rewrite the file with multiple lines
        static filemanager rewrite(const std::string &path, const std::vector<std::string> &lines);

        // check if the file or directory is empty
        bool is_empty();

        // check if a file or directory is empty
        static bool is_empty(const std::string &path);

        // get the amount of lines the file has
        int lines();

        // get the amount of lines a file has
        static int lines(const std::string &path);

        // append content to the last line of the file
        filemanager &append(const std::string &content);

        // append content to the last line of a file
        static filemanager append(const std::string &path, const std::string &content);

        // append content to the last line of the file
        filemanager &operator+=(const std::string &content);

        // end line
        filemanager &endl();

        // flush
        filemanager &flush();

        // end line
        static filemanager endl(const std::string &path);

        // flush
        static filemanager flush(const std::string &path);

        // truncate the file
        filemanager &trunc();

        // truncate a file
        static filemanager trunc(const std::string &path);

		// General Unknown filemanager Exceptions
		class unknown_exception : public std::exception
		{
			[[nodiscard]] const char* what() const noexcept override;
		};

		// Path Not Found Error: Thrown when a path is not found
		class path_not_found_exception : public std::exception
		{
			[[nodiscard]] const char* what() const noexcept override;
		};

		class error : public std::exception
		{
			private:
			const char *message;
			
			public:
			error();

			error(const char *message);

			error(const std::string &message);

			[[nodiscard]] const char *what() const noexcept;

			[[nodiscard]] const char *output() const noexcept;
		};
    };




} // posh

#endif // POSH_FILEMANAGER_HH
