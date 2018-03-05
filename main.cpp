#include <vector>
#include <string>
#include <cmath>

#include "password.hpp"

using namespace std;

const char ZERO = '0';
const char CAPITAL_A = 'A';
const char LOWER_A = 'a';

int main(int argc, char** argv) {

    if (argc < 3) {
	std::cout << "Incorrect number of arguments" << std::endl;
	return 0;
    }

    // Get the R and hash from command line
    int passwordLength = stoi(argv[1]);
    string hash(argv[2]);
    
    string currentGuess;
    vector<char> characterSet;
    for (short c = ZERO ; c <= (ZERO + 9) ; c++) characterSet.push_back(c); // 0-9
    for (char c = CAPITAL_A ; c <= (CAPITAL_A + 25) ; c++) characterSet.push_back(c); // A-Z
    for (char c = LOWER_A ; c <= (LOWER_A + 25) ; c++) characterSet.push_back(c); // a-z

    crackPassword(currentGuess,passwordLength,characterSet,hash);

    return 0;
}
