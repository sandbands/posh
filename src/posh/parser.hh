/**
 * @file parser.hh
 * @author your name (you@domain.com)
 * @brief Parser Functionality
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef POSH_PARSER_HH
#define POSH_PARSER_HH

#include <map>
#include <string>
#include <vector>

namespace posh
{

	class parser
	{
		private:
		// Vector to store the command line arguments
		std::vector<std::string> args;

		// Map to store the flags and their corresponding values
		std::map<std::string, std::string> flags;
		
		
		public:
		// Constructor that initializes the parser object with the command line arguments
		parser(const int argc, const char *argv[]);

		// Returns the command line argument at the specified index
		std::string get_arg(const int index);

		// Returns the number of command line arguments
		int get_arg_count();

		// Checks if the specified flag is present in the flags map
		bool has_flag(const std::string &flag);

		// Returns the value of the specified flag from the flags map
		// If the flag is not present, returns an empty string
		std::string get_flag_value(const std::string &flag);
	};

	// Declares an external variable named CommandEngine of type parser*
	extern parser *CommandEngine;

} // posh

#endif // POSH_PARSER_HH


