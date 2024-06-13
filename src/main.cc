#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "posh/posh.hh"
#include "posh/file_helper.hh"
#include "posh/utils.cc"



/**
+ * @brief Main function of the program
+ * @return int - The exit status of the program
+ *
+ * This function prints "hello world" to the standard output and
+ * calls the starts_with function from the posh namespace. The
+ * function starts_with checks if the string "abcdefg" starts with
+ * the character 'a' and returns 0 if true.
+ */
int main() {
	// Print "hello world" to the standard output
	std::cout << "hello world" << std::endl;

	// Call the starts_with function from the posh namespace
	// The function checks if the string "abcdefg" starts with
	// the character 'a' and returns 0 if true.
	// The function starts_with has three parameters:
	// - The string to check
	// - The character type to check for
	// - The number of characters to check for
	posh::starts_with("abcdefg", posh::CT_ALPHA , 4);

	// Return 0 to indicate successful execution of the program
	return 0;
}


