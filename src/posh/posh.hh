/**
 * @file posh.hh
 * @author your name (you@domain.com)
 * @brief posh Library
 * @version 0.1
 * @date 06/12/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef POSH_POSH_HH
#define POSH_POSH_HH

#include <exception>

#define VERSION_NUMBER "1.00.12"
#define BUILD_STABLE "-S"
#define BUILD_ALPHA "-A"
#define BUILD_DEV "-D"
#define BUILD_CANARY "-C"

#define VERSION (VERSION_NUMBER + BUILD_ALPHA)

namespace posh
{
	// Thrown when a process, operation, or function, is terminated early
	class early_termination_exception : public std::exception
	{
		public:
		[[nodiscard]] const char* what() const noexcept override;
	};

	// CharTypes
	typedef enum CharType
	{
		CT_ALPHA,	   // Letters (abcdefghijklmnopqrstuvwxyzABCDEVGHIJKLMNOPQRSTUVWXYZ)
		CT_MISC,		// Miscellaneous characters (~!@#$%^&*()_+`-={}[]|\:;"'<>,.?/)
		CT_INT,		 // Numbers (positive integers: 0123456789)
		CT_MATH,		// Mathematical characters (!%^*-+=/)
		CT_LOGIC,	   // Logical operator characters (!&|)
	} CharType;

	// SizeTypes
	typedef enum SizeType
	{
		ST_EMPTY,	   // Empty, or Blank
		ST_DYNAMIC,	 // Size can change throughout the program
		ST_STATIC	   // Size must remain the same throughout the program
	} SizeType;
}

#endif // POSH_POSH_HH


