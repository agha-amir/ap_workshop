#include <iostream>
#include <string>
#include <regex>

using namespace std;
bool validateCommand(string& str, string &error);
bool validateFlags(string& str, string* flags, int flagCount, string &error);
bool validateRegister(string& str, string &error);
string validateData(string& str, string &error);
string validateBio(string& str, string &error);
void analyzeBio(string& bio);
void analyzePhone(string& phone);


