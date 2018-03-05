#ifndef PASS_H
#define PASS_H

#include <vector>
#include <iostream>
#include <string>

#include "hash.hpp"

// -----------------------------------------------------------------------------------
void testThePassword(const std::string& password, const std::string& hash) {
    std::string passwordHash = hashString(password);
    // Print the password and the last 7 characters of hash (hash length is 64)
    std::cout << password << " " << passwordHash.substr(57) << "\n";  
    if (passwordHash == hash) {
	std::cout << "\n" << password << " matches " << hash << std::endl;
	exit(0);
    }
}

// ----------------------------------------------------------------------------------

void crackPassword(std::string& currentGuess, 
		   const int passwordLength,
		   const std::vector<char>& characterSet,
		   const std::string& hash) {    
    if (currentGuess.size() == passwordLength) {
	testThePassword(currentGuess,hash);
    } else {
	for (char character : characterSet) {
	    currentGuess.push_back(character);
	    crackPassword(currentGuess, passwordLength, characterSet, hash);
	    currentGuess.pop_back();
	}
    }
}

#endif
