/**
 * @file parser.cc
 * @author your name (you@domain.com)
 * @brief Parser Functionality
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "parser.hh"

namespace posh
{
	

// Constructor for the parser class
	parser::parser(const int argc, const char *argv[])
	{
		// Iterate over the command-line arguments
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			
			// Check if the argument is a flag
			if (arg.substr(0, 2) == "--")
			{
				std::string flag = arg.substr(2); // Extract the flag name
				std::string value = "";
				
				// Check if there is a value for the flag
				if (i + 1 < argc && argv[i + 1][0] != '-')
				{
					value = argv[i + 1]; // Set the value to the next argument
					i++; // Increment the loop counter to skip the value
				}
				
				// Store the flag and its value in the flags map
				this->flags[flag] = value;
			}

			// Check if the argument is a short flag
			else if (arg.substr(0, 1) == "-")
			{
				std::string flag = arg.substr(1, 1); // Extract the flag name
				std::string value = "";
				
				// Check if there is a value for the flag
				if (i + 1 < argc && argv[i + 1][0] != '-')
				{
					value = argv[i + 1]; // Set the value to the next argument
					i++; // Increment the loop counter to skip the value
				}
				
				// Store the flag and its value in the flags map
				this->flags[flag] = value;
			} 
			
			// If the argument is not a flag, add it to the args vector
			else
			{
				this->args.push_back(arg);
			}
		}
	}

// Returns the argument at the specified index
	std::string parser::get_arg(const int index)
	{
		// Check if the index is within the bounds of the args vector
		if (index >= 0 && index < this->args.size())
		{
			// Return the argument at the specified index
			return this->args[index];
		}
		
		// If the index is out of bounds, return an empty string
		return "";
	}

	// Returns the number of arguments stored in the args vector
	int parser::get_arg_count()
	{
		// Return the size of the args vector
		return this->args.size();
	}


	// Checks if a flag exists in the flags map
	bool parser::has_flag(const std::string &flag)
	{
		// Return true if the flag is found in the flags map, otherwise false
		return this->flags.find(flag) != this->flags.end();
	}


	// Returns the value of a flag if it exists, otherwise returns an empty string
	std::string parser::get_flag_value(const std::string &flag)
	{
		// Check if the flag exists in the flags map
		if (this->has_flag(flag))
		{
			// Return the value of the flag
			return this->flags[flag];
		}
		
		// If the flag does not exist, return an empty string
		else
		{
			return "";
		}
	}

	// Declares an external variable named CommandEngine of type parser*
	extern parser *CommandEngine;


} // posh


