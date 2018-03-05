#ifndef HASH_H
#define HASH_H

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <openssl/sha.h>

std::string to_hex(unsigned char s) {
    std::stringstream ss;
    ss << std::hex << (int) s;
    std::string retString(ss.str());
    if (retString.size() == 1) {
	std::string big("0");
	big += retString;
	retString = big;
    }
    return retString;
}  

std::string hashString(const std::string& stringForHashing) {
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, stringForHashing.c_str(), stringForHashing.length());
    SHA256_Final(hash, &sha256);

    std::string output = "";    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        output += to_hex(hash[i]);
    }    
    return output;
}

#endif
