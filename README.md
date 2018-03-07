# Building for Windows

Add the source files (.cpp and .hpp but NOT .sh) to a VS project.

Add the password length and the hash to crack in the command line arguments (right click the project in VS -> Properties -> Configuration Properties -> Debugging -> Command Arguments).

Run using 'Local Windows Debugger' and put a breakpoint before the return statement in main and the exit statement in testThePassword on line 17 of password.hpp).

To generate a hash: type 'SHA256 <string>' into DuckDuckGo.com. For example 'SHA256' provides the hash '5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8' at the top of the results page.

# Linux/macOS build script

```./build_g++.sh```

Requires GCC and OpenSSL installed on build computer. If you can't install OpenSSL, define _WIN32 to use the backup code intended for Windows.

## macOS OpenSSL install

```brew install openssl```

Assuming that you have the homebrew package manager installed (you should). If you can't install OpenSSL, define _WIN32 to use the backup code intended for Windows.

