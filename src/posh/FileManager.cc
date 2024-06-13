/**
 * @file FileManager.cc
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
#include "FileManager.hh"

namespace posh {
	/**
	 * Define the File Helper Class
	 */

	// file helper constructor
	FileManager::FileManager(std::string path) : path(std::move(path)) {}

	// get path
	const std::string &FileManager::get_path()
	{
		return this->path;
	}

	// set path
	const std::string &FileManager::set_path(const std::string &new_path)
	{
		this->path = new_path;
		return this->path;
	}

	// check if the file exists already, returns false if it does not or if it is a directory
	bool FileManager::exists()
	{
		return std::filesystem::exists(this->path) && !(std::filesystem::is_directory(this->path));
	}

	// check if a file exists already, returns false if it does not or if it is a directory
	bool FileManager::exists(const std::string &path)
	{
		return std::filesystem::exists(path) && !(std::filesystem::is_directory(path));
	}

	// create the file
	FileManager &FileManager::create()
	{
		std::fstream file;
		file.open(this->path, std::ios::out);
		file.close();
		return *this;
	}

	// create a file
	FileManager FileManager::create(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out);
		file.close();
		return FileManager(path);
	}

	// delete the file
	bool FileManager::remove()
	{
		return std::filesystem::remove(this->path);
	}

	// delete a file
	bool FileManager::remove(const std::string &path)
	{
		return std::filesystem::remove(path);
	}

	// read the file and get all the content inside one string
	std::string FileManager::read()
	{
		std::vector<std::string> lines = FileManager::read_all();
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
	std::string FileManager::read(const std::string &path)
	{
		std::vector<std::string> lines = FileManager::read_all(path);
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
	std::vector<std::string> FileManager::read_all()
	{
		std::vector<std::string> content;

		std::fstream file;
		file.open(this->path);

		for (std::string line; std::getline(file, line);) content.push_back(line);

		file.close();

		return content;
	}

	// read a file and return a vector of its lines
	std::vector<std::string> FileManager::read_all(const std::string &path)
	{
		std::vector<std::string> content;

		std::fstream file;
		file.open(path);

		for (std::string line; std::getline(file, line);) content.push_back(line);

		file.close();

		return content;
	}

	// read the file and return a vector of specific lines
	std::vector<std::string> FileManager::read_lines(const std::vector<int> &lines)
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
	std::vector<std::string> FileManager::read_lines(const std::string &path, const std::vector<int> &lines)
	{
		std::vector<std::string> result, all_lines;
		all_lines = FileManager::read_all(path);

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
	std::string FileManager::read_line(const int &line)
	{
		std::vector<std::string> lines;
		lines = posh::FileManager::read_all(this->path);

		for (int i = 0; i < (int) lines.size(); i++)
		{
			if (i == line-1) return lines[line];
		}

		return "";
	}

	// read a file and return a specific line
	std::string FileManager::read_line(const std::string &path, const int &line)
	{
		std::vector<std::string> lines;
		lines = FileManager::read_all(path);

		for (int i = 0; i < (int) lines.size(); i++)
		{
			if (i == line-1) return lines[line];
		}

		return "";
	}

	// erase the file contents
	FileManager &FileManager::erase()
	{
		std::filesystem::path file_path(this->path);

		// throw error if path does not exist
		if (!std::filesystem::exists(file_path))
		{
			throw FileManager::error("File \"" + this->path + "\" does not exist.");
			return *this;
		}

		// throw error if path is a directory
		else if (std::filesystem::is_directory(file_path))
		{
			throw FileManager::error("Path \"" + this->path + "\" is a directory.");
			return *this;
		}

		std::fstream file;
		file.open(file_path, std::ios::out | std::ios::trunc); // open in trunc mode
		file.close();
		return *this;
	}

	// erase a file's contents
	FileManager FileManager::erase(const std::string &path)
	{
		std::filesystem::path file_path(path);

		// throw error if path does not exist
		if (!std::filesystem::exists(file_path))
		{
			throw FileManager::error("File \"" + path + "\" does not exist.");
			return FileManager(path);
		}

		// throw error if path is a directory
		else if (std::filesystem::is_directory(file_path))
		{
			throw FileManager::error("Path \"" + path + "\" is a directory.");
			return FileManager(path);
		}

		std::fstream file;
		file.open(file_path, std::ios::out | std::ios::trunc); // open in trunc mode
		file.close();
		return FileManager(file_path);
	}

	// write a line to the file
	FileManager &FileManager::write(const std::string &line)
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
	FileManager FileManager::write(const std::string &path, const std::string &line)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode

		// if it's the first line, then don't add a newline character
		if (FileManager::read_all(path).empty()) file << line;

		// otherwise, add the content to a new line
		else file << "\n" << line;

		file.close();
		return FileManager(path);
	}

	// write a line to the file, using the insertion operator
	FileManager &FileManager::operator<<(const std::string &line)
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
	FileManager &FileManager::write(const std::vector<std::string> &lines)
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
	FileManager FileManager::write(const std::string &path, const std::vector<std::string> &lines)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode

		if (lines.empty())
		{
			// if it's the first line, then don't add a newline character
			if (FileManager::read_all(path).empty()) file << lines[0];
		}

		// don't attempt the next loop which starts at index 1 if there is only 1 item
		if (lines.size() < 2) return FileManager(path);

		for (int i = 1; i < (int) lines.size(); i++)
		{
			// only end if it's not the last line
			if (i != (int) lines.size() - 1) file << lines[i] << std::endl;

			// otherwise don't end it
			else file << lines[i];
		}

		file.close();
		return FileManager(path);
	}

	// write lines to the file, using the insertion operator
	FileManager &FileManager::operator<<(const std::vector<std::string> &lines)
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
	bool FileManager::is_open()
	{
		std::fstream file(this->path);
		return file.is_open();
	}

	// check if a file is currently open
	bool FileManager::is_open(const std::string &path)
	{
		std::fstream file(path);
		return file.is_open();
	}

	// get the file's size
	int FileManager::size()
	{
		return (int) std::filesystem::file_size(this->path);
	}

	// get a file's size
	int FileManager::size(const std::string &path)
	{
		return (int) std::filesystem::file_size(path);
	}

	// create a directory
	bool FileManager::mkdir(const std::string &path)
	{
		return std::filesystem::create_directory(path);
	}

	// remove a directory
	bool FileManager::rmdir(const std::string &path)
	{
		return std::filesystem::remove_all(path);
	}

	// duplicate the file, returns the new file
	FileManager FileManager::duplicate()
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

		return FileManager(new_path);
	}

	// duplicate a file, returns the new file
	FileManager FileManager::duplicate(const std::string &path)
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

		return FileManager(new_path);
	}

	// duplicate the file to another location, returns the new file
	FileManager &FileManager::duplicate_to(const std::string &path2)
	{
		std::filesystem::copy_file(this->path, path2);
		return *this;
	}

	// duplicate a file to another location, returns the new file
	FileManager FileManager::duplicate_to(const std::string &path1, const std::string &path2)
	{
		std::filesystem::copy_file(path1, path2);
		return FileManager(path2);
	}

	// move the file to a new location
	FileManager &FileManager::move_to(const std::string &new_path)
	{
		this->duplicate_to(new_path);
		this->remove();
		this->set_path(new_path);
		return *this;
	}

	// move a file to a new location
	FileManager FileManager::move_to(const std::string &path1, const std::string &path2)
	{
		FileManager::duplicate_to(path1, path2);
		FileManager::remove(path1);
		return FileManager(path2);
	}

	// rename the file (not recommended for objects, use static method instead)
	FileManager &FileManager::rename(const std::string &new_name)
	{
		std::rename(this->path.c_str(), new_name.c_str());
		this->path = new_name;
		return *this;
	}

	// rename a file
	FileManager FileManager::rename(const std::string &path, const std::string &new_name)
	{
		std::rename(path.c_str(), new_name.c_str());
		return FileManager(new_name);
	}

	// rewrite the file with one string
	FileManager &FileManager::rewrite(const std::string &content)
	{
		this->erase();
		return this->write(content);
	}

	// rewrite a file with one string
	FileManager FileManager::rewrite(const std::string &path, const std::string &content)
	{
		FileManager::erase(path);
		return FileManager::write(path, content);
	}

	// rewrite a file with multiple lines
	FileManager &FileManager::rewrite(const std::vector<std::string> &lines)
	{
		this->erase();
		return this->write(lines);
	}

	// rewrite the file with multiple lines
	FileManager FileManager::rewrite(const std::string &path, const std::vector<std::string> &lines)
	{
		FileManager::erase(path);
		return FileManager::write(path, lines);
	}

	// check if the file or directory is empty
	bool FileManager::is_empty()
	{
		return std::filesystem::is_empty(this->path);
	}

	// check if a file or directory is empty
	bool FileManager::is_empty(const std::string &path)
	{
		return std::filesystem::is_empty(path);
	}

	// get the amount of lines the file has
	int FileManager::lines()
	{
		return (int) FileManager::read_all().size();
	}

	// get the amount of lines a file has
	int FileManager::lines(const std::string &path)
	{
		return (int) FileManager::read_all(path).size();
	}

	// append content to the last line of the file
	FileManager &FileManager::append(const std::string &content)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return *this;
	}

	// append content to the last line of a file
	FileManager FileManager::append(const std::string &path, const std::string &content)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return FileManager(path);
	}

	// append content to the last line of the file
	FileManager &FileManager::operator+=(const std::string &content)
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << content;
		file.close();
		return *this;
	}

	// end line
	FileManager &FileManager::endl()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file << std::endl;
		file.close();
		return *this;
	}

	// flush
	FileManager &FileManager::flush()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::app); // open in append mode
		file.flush();
		file.close();
		return *this;
	}

	// end line
	FileManager FileManager::endl(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file << std::endl;
		file.close();
		return FileManager(path);
	}

	// flush the file
	FileManager FileManager::flush(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::app); // open in append mode
		file.flush();
		file.close();
		return FileManager(path);
	}

	// truncate the file
	FileManager &FileManager::trunc()
	{
		std::fstream file;
		file.open(this->path, std::ios::out | std::ios::trunc); // open in truncate mode
		file.close();
		return *this;
	}

	// truncate a file
	FileManager FileManager::trunc(const std::string &path)
	{
		std::fstream file;
		file.open(path, std::ios::out | std::ios::trunc); // open in truncate mode
		file.close();
		return FileManager(path);
	}


	// General Unknown FileManager Exceptions
	const char *FileManager::unknown_exception::what() const noexcept
	{
		return "\n[FileManager::unknown_exception] An Unknown Exception Occurred.\n";
	}

	// Thrown when a path is not found
	const char *FileManager::path_not_found_exception::what() const noexcept
	{
		return "\n[FileManager::path_not_found_exception] Path(s) Could Not Be Found Or Recognized.\n";
	}

	FileManager::error::error()
	{
		this->message = (const char*)"\n[FileManager::error] An Error Occurred.\n";
	}

	FileManager::error::error(const char *message)
	{
		this->message = (const char*)("\n[FileManager::error] " + std::string(message) + ".\n").c_str();
	}

	FileManager::error::error(const std::string &message)
	{
		this->message = (const char*)("\n[FileManager::error] " + message + ".\n").c_str();
	}

	const char *FileManager::error::error::what() const noexcept
	{
		return this->message;
	}

	const char *FileManager::error::error::output() const noexcept
	{
		std::cout << this->message << std::endl;
		return this->message;
	}
}


/*
 * https://en.cppreference.com/w/cpp/filesystem/path/replace_extension
 * */


