/**
 * @file filemanager.cc
 * @author your name (you@domain.com)
 * @brief File Management 
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <fstream>
#include <filesystem>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include "filemanager.hh"

namespace posh
{
	/**
	 * Define the File Helper Class
	 */

	// file helper constructor
	filemanager::filemanager(const std::string &path)
	{
		this->path = path;
	}

	// file helper constructor
	filemanager::filemanager(const char *path)
	{
		this->path = std::string(path);
	}

	// get path
	const std::string &filemanager::get_path()
	{
		return this->path;
	}

	// set path
	const std::string &filemanager::set_path(const std::string &new_path)
	{
		this->path = new_path;
		return this->path;
	}

	// check if the file exists already, returns false if it does not or if it is a directory
	bool filemanager::exists()
	{
		return std::filesystem::exists(this->path) && !(std::filesystem::is_directory(this->path));
	}

	// check if a file exists already, returns false if it does not or if it is a directory
	bool filemanager::exists(const std::string &path)
	{
		return std::filesystem::exists(path) && !(std::filesystem::is_directory(path));
	}

	// create the file
	filemanager &filemanager::create()
	{
		std::fstream file;
		file.open(this->path, std::ios::out);
		file.close();
		return *this;
	}

	// create a file
	filemanager filemanager::create(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out);
		file.close();
		return filemanager(path);
	}

	// delete the file
	bool filemanager::remove()
	{
		return std::filesystem::remove(this->path);
	}

	// delete a file
	bool filemanager::remove(const std::string &path)
	{
		return std::filesystem::remove(path);
	}

	// read the file and get all the content inside one string
	std::string filemanager::read()
	{
		std::vector<std::string> lines = filemanager::read_all();
		std::string content;

		for (int i = 0; i < (int) lines.size(); i++)
		{
			// don't add another newline character if it's the last line
			if (i == (int) lines.size() - 1) content += lines[i];

			// otherwise, add a newline
			else content += lines[i] + "\n";
		}

		return content;
	}

	// read a file and get all the content inside one string
	std::string filemanager::read(const std::string &path)
	{
		std::vector<std::string> lines = filemanager::read_all(path);
		std::string content;

		for (int i = 0; i < (int) lines.size(); i++)
		{
			// don't add another newline character if it's the last line
			if (i == (int) lines.size() - 1) content += lines[i];

			// otherwise, add a newline
			else content += lines[i] + "\n";
		}

		return content;
	}

	// read the file and return a vector of its lines
	std::vector<std::string> filemanager::read_all()
	{
		std::vector<std::string> content;

		std::fstream file;
		file.open(this->path);

		for (std::string line; std::getline(file, line);) content.push_back(line);

		file.close();

		return content;
	}

	// read a file and return a vector of its lines
	std::vector<std::string> filemanager::read_all(const std::string &path)
	{
		std::vector<std::string> content;

		std::fstream file;
		file.open(path);

		for (std::string line; std::getline(file, line);) content.push_back(line);

		file.close();

		return content;
	}

	// read the file and return a vector of specific lines
	std::vector<std::string> filemanager::read_lines(const std::vector<int> &lines)
	{
		std::vector<std::string> result, all_lines;
		all_lines = this->read_all();

		for (int i = 0; i < (int) all_lines.size(); i++)
		{
			for (int j = 0; j < (int) lines.size(); j++)
			{
				if (i == lines[j+1]) result.push_back(all_lines[i]);
			}
		}

		return result;
	}

	// read a file and return a vector of specific lines
	std::vector<std::string> filemanager::read_lines(const std::string &path, const std::vector<int> &lines)
	{
		std::vector<std::string> result, all_lines;
		all_lines = filemanager::read_all(path);

		for (int i = 0; i < (int) all_lines.size(); i++)
		{
			for (int j = 0; j < (int) lines.size(); j++)
			{
				if (i == lines[j+1]) result.push_back(all_lines[i]);
			}
		}

		return result;
	}

	// read the file and return a specific line
	std::string filemanager::read_line(const int line)
	{
		std::vector<std::string> lines;
		lines = posh::filemanager::read_all(this->path);

		for (int i = 0; i < (int) lines.size(); i++)
		{
			if (i == line-1) return lines[line];
		}

		return "";
	}

	// read a file and return a specific line
	std::string filemanager::read_line(const std::string &path, const int line)
	{
		std::vector<std::string> lines;
		lines = filemanager::read_all(path);

		for (int i = 0; i < (int) lines.size(); i++)
		{
			if (i == line-1) return lines[line];
		}

		return "";
	}

	// erase the file contents
	filemanager &filemanager::erase()
	{
		std::filesystem::path file_path(this->path);

		// throw error if path does not exist
		if (!std::filesystem::exists(file_path))
		{
			throw filemanager::error("File \"" + this->path + "\" does not exist.");
			return *this;
		}

		// throw error if path is a directory
		else if (std::filesystem::is_directory(file_path))
		{
			throw filemanager::error("Path \"" + this->path + "\" is a directory.");
			return *this;
		}

		std::fstream file;
		file.open(file_path, std::ios::out | std::ios::trunc); // open in trunc mode
		file.close();
		return *this;
	}

	// erase a file's contents
	filemanager filemanager::erase(const std::string &path)
	{
		std::filesystem::path file_path(path);

		// throw error if path does not exist
		if (!std::filesystem::exists(file_path))
		{
			throw filemanager::error("File \"" + path + "\" does not exist.");
			return filemanager(path);
		}

		// throw error if path is a directory
		else if (std::filesystem::is_directory(file_path))
		{
			throw filemanager::error("Path \"" + path + "\" is a directory.");
			return filemanager(path);
		}

		std::fstream file;
		file.open(file_path, std::ios::out | std::ios::trunc); // open in trunc mode
		file.close();
		return filemanager(file_path);
	}

	// write a line to the file
	filemanager &filemanager::write(const std::string &line)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode

		// if it's the first line, then don't add a newline character
		if (this->read_all().empty()) file << line;

		// otherwise, add the content to a new line
		else file << "\n" << line;

		file.close();
		return *this;
	}

	// write a line to a file
	filemanager filemanager::write(const std::string &path, const std::string &line)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode

		// if it's the first line, then don't add a newline character
		if (filemanager::read_all(path).empty()) file << line;

		// otherwise, add the content to a new line
		else file << "\n" << line;

		file.close();
		return filemanager(path);
	}

	// write a line to the file, using the insertion operator
	filemanager &filemanager::operator<<(const std::string &line)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode

		// if it's the first line, then don't add a newline character
		if (this->read_all().empty()) file << line;

		// otherwise, add the content to a new line
		else file << "\n" << line;

		file.close();
		return *this;
	}

	// write lines to the file
	filemanager &filemanager::write(const std::vector<std::string> &lines)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode

		if (lines.empty())
		{
			// if it's the first line, then don't add a newline character
			if (this->read_all().empty()) file << lines[0];
		}

		// don't attempt the next loop which starts at index 1 if there is only 1 item
		if (lines.size() < 2) return *this;

		for (int i = 1; i < (int) lines.size(); i++)
		{
			// only end if it's not the last line
			if (i != (int) lines.size() - 1) file << lines[i] << std::endl;

			// otherwise don't end it
			else file << lines[i];
		}

		file.close();
		return *this;
	}

	// write lines to a file
	filemanager filemanager::write(const std::string &path, const std::vector<std::string> &lines)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode

		if (lines.empty())
		{
			// if it's the first line, then don't add a newline character
			if (filemanager::read_all(path).empty()) file << lines[0];
		}

		// don't attempt the next loop which starts at index 1 if there is only 1 item
		if (lines.size() < 2) return filemanager(path);

		for (int i = 1; i < (int) lines.size(); i++)
		{
			// only end if it's not the last line
			if (i != (int) lines.size() - 1) file << lines[i] << std::endl;

			// otherwise don't end it
			else file << lines[i];
		}

		file.close();
		return filemanager(path);
	}

	// write lines to the file, using the insertion operator
	filemanager &filemanager::operator<<(const std::vector<std::string> &lines)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode

		if (lines.empty())
		{
			// if it's the first line, then don't add a newline character
			if (this->read_all().empty()) file << lines[0];
		}

		// don't attempt the next loop which starts at index 1 if there is only 1 item
		if (lines.size() < 2) return *this;

		for (int i = 1; i < (int) lines.size(); i++)
		{
			// only end if it's not the last line
			if (i != (int) lines.size() - 1) file << lines[i] << std::endl;

			// otherwise don't end it
			else file << lines[i];
		}

		file.close();
		return *this;
	}

	// check if the file is currently open
	bool filemanager::is_open()
	{
		std::fstream file(this->path);
		return file.is_open();
	}

	// check if a file is currently open
	bool filemanager::is_open(const std::string &path)
	{
		std::fstream file(path);
		return file.is_open();
	}

	// get the file's size
	int filemanager::size()
	{
		return (int) std::filesystem::file_size(this->path);
	}

	// get a file's size
	int filemanager::size(const std::string &path)
	{
		return (int) std::filesystem::file_size(path);
	}

	// create a directory
	bool filemanager::mkdir(const std::string &path)
	{
		return std::filesystem::create_directory(path);
	}

	// remove a directory
	bool filemanager::rmdir(const std::string &path)
	{
		return std::filesystem::remove_all(path);
	}

	// duplicate the file, returns the new file
	filemanager filemanager::duplicate()
	{
		std::string new_path = this->path;
		std::string ext = std::filesystem::path(this->path).extension().string();

		// get the length of file extension so that we know how much to trim off
		int ext_length = (int) ext.size();

		// fill the new_path string with the contents of this->path, excluding the file extension
		for (int i = 0; i < (int) this->path.size() - ext_length; i++) new_path += this->path[i];

		// check for other duplicates and increment the number
		for (int i = 1;; i++)
		{
			if (std::filesystem::exists((new_path + "-" + std::to_string(i)))) continue;
			
			else
			{
				new_path += ("-" + std::to_string(i) + ext);
				break;
			}
		}

		return filemanager(new_path);
	}

	// duplicate a file, returns the new file
	filemanager filemanager::duplicate(const std::string &path)
	{
		std::string new_path = path;
		std::string ext = std::filesystem::path(path).extension().string();

		// get the length of file extension so that we know how much to trim off
		int ext_length = (int) ext.size();

		// fill the new_path string with the contents of path, excluding the file extension
		for (int i = 0; i < (int) path.size() - ext_length; i++) new_path += path[i];

		// check for other duplicates and increment the number
		for (int i = 1;; i++)
		{
			if (std::filesystem::exists((new_path + "-" + std::to_string(i)))) continue;
			
			else
			{
				new_path += ("-" + std::to_string(i) + ext);
				break;
			}
		}

		return filemanager(new_path);
	}

	// duplicate the file to another location, returns the new file
	filemanager &filemanager::duplicate_to(const std::string &path2)
	{
		std::filesystem::copy_file(this->path, path2);
		return *this;
	}

	// duplicate a file to another location, returns the new file
	filemanager filemanager::duplicate_to(const std::string &path1, const std::string &path2)
	{
		std::filesystem::copy_file(path1, path2);
		return filemanager(path2);
	}

	// move the file to a new location
	filemanager &filemanager::move_to(const std::string &new_path)
	{
		this->duplicate_to(new_path);
		this->remove();
		this->set_path(new_path);
		return *this;
	}

	// move a file to a new location
	filemanager filemanager::move_to(const std::string &path1, const std::string &path2)
	{
		filemanager::duplicate_to(path1, path2);
		filemanager::remove(path1);
		return filemanager(path2);
	}

	// rename the file (not recommended for objects, use static method instead)
	filemanager &filemanager::rename(const std::string &new_name)
	{
		std::rename(this->path.c_str(), new_name.c_str());
		this->path = new_name;
		return *this;
	}

	// rename a file
	filemanager filemanager::rename(const std::string &path, const std::string &new_name)
	{
		std::rename(path.c_str(), new_name.c_str());
		return filemanager(new_name);
	}

	// rewrite the file with one string
	filemanager &filemanager::rewrite(const std::string &content)
	{
		this->erase();
		return this->write(content);
	}

	// rewrite a file with one string
	filemanager filemanager::rewrite(const std::string &path, const std::string &content)
	{
		filemanager::erase(path);
		return filemanager::write(path, content);
	}

	// rewrite a file with multiple lines
	filemanager &filemanager::rewrite(const std::vector<std::string> &lines)
	{
		this->erase();
		return this->write(lines);
	}

	// rewrite the file with multiple lines
	filemanager filemanager::rewrite(const std::string &path, const std::vector<std::string> &lines)
	{
		filemanager::erase(path);
		return filemanager::write(path, lines);
	}

	// check if the file or directory is empty
	bool filemanager::is_empty()
	{
		return std::filesystem::is_empty(this->path);
	}

	// check if a file or directory is empty
	bool filemanager::is_empty(const std::string &path)
	{
		return std::filesystem::is_empty(path);
	}

	// get the amount of lines the file has
	int filemanager::lines()
	{
		return (int) filemanager::read_all().size();
	}

	// get the amount of lines a file has
	int filemanager::lines(const std::string &path)
	{
		return (int) filemanager::read_all(path).size();
	}

	// append content to the last line of the file
	filemanager &filemanager::append(const std::string &content)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return *this;
	}

	// append content to the last line of a file
	filemanager filemanager::append(const std::string &path, const std::string &content)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return filemanager(path);
	}

	// append content to the last line of the file
	filemanager &filemanager::operator+=(const std::string &content)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return *this;
	}

	// end line
	filemanager &filemanager::endl()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << std::endl;
		file.close();
		return *this;
	}

	// flush
	filemanager &filemanager::flush()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file.flush();
		file.close();
		return *this;
	}

	// end line
	filemanager filemanager::endl(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file << std::endl;
		file.close();
		return filemanager(path);
	}

	// flush the file
	filemanager filemanager::flush(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file.flush();
		file.close();
		return filemanager(path);
	}

	// truncate the file
	filemanager &filemanager::trunc()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::trunc); // open in truncate mode
		file.close();
		return *this;
	}

	// truncate a file
	filemanager filemanager::trunc(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::trunc); // open in truncate mode
		file.close();
		return filemanager(path);
	}


	// General Unknown filemanager Exceptions
	const char *filemanager::unknown_exception::what() const noexcept
	{
		return "\n[filemanager::unknown_exception] An Unknown Exception Occurred.\n";
	}

	// Thrown when a path is not found
	const char *filemanager::path_not_found_exception::what() const noexcept
	{
		return "\n[filemanager::path_not_found_exception] Path(s) Could Not Be Found Or Recognized.\n";
	}

	filemanager::error::error()
	{
		this->message = (const char*)"\n[filemanager::error] An Error Occurred.\n";
	}

	filemanager::error::error(const char *message)
	{
		this->message = (const char*)("\n[filemanager::error] " + std::string(message) + ".\n").c_str();
	}

	filemanager::error::error(const std::string &message)
	{
		this->message = (const char*)("\n[filemanager::error] " + message + ".\n").c_str();
	}

	const char *filemanager::error::error::what() const noexcept
	{
		return this->message;
	}

	const char *filemanager::error::error::output() const noexcept
	{
		std::cout << this->message << std::endl;
		return this->message;
	}
}


/*
 * https://en.cppreference.com/w/cpp/filesystem/path/replace_extension
 * */


