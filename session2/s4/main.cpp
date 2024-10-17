#include "string.h"
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include <sstream>
using namespace std;
int main() {
    string input;
    string error;
    bool isRegistered = false; 
    bool isDataEntered = false;
    bool bioCompleted = false;

    string firstName, lastName, email, phoneNumber, bioDescription;

    while (true) {
        cout << "enter your command (register, data, or bio): ";
        getline(cin, input);
        input.erase(0, input.find_first_not_of(" \t\n"));
        input.erase(input.find_last_not_of(" \t\n") + 1);

        
        if (!validateCommand(input, error))
        {
            cout<<error<<endl;
            continue;
        }
        
        if (!isRegistered && input.substr(0, 8) != "register") {
            cout << "you must complete the registration first" << endl;
            continue;
        }

        if (isRegistered && !isDataEntered && input.substr(0, 4) != "data") {
            cout << "you must enter data after registering" << endl;
            continue; 
        }

        if (isDataEntered && !bioCompleted && input.substr(0, 3) != "bio") {
            cout << "you must complete your bio after entering data" << endl;
            continue; 
        }
        if (input.substr(0, 8) == "register") {
            string flags[] = { "-u", "-p" };
            if (!validateFlags(input, flags, 2, error)) {
                cout << error << endl;
                continue;
            }
            if (validateRegister(input, error)) {
                cout << "register successful" << endl;
                isRegistered = true;
            } else {
                cout << error << endl;
            }
        }
        else if (input.substr(0, 4) == "data") {
            string flags[] = { "-fn", "-ln", "-e", "-ph" };
            if (!validateFlags(input, flags, 4, error)) {
                cout << error << endl;
                continue;
            }

            string result = validateData(input, error);
            if (!result.empty()) {
                cout << "data saved successfully" << endl;
                //cout << result << endl;
                size_t firstSpace = result.find(' ');
                firstName = result.substr(0, firstSpace);
                size_t lastSpace = result.find('\n');
                lastName = result.substr(firstSpace + 1, lastSpace - firstSpace - 1);
                email = result.substr(result.find("Email: ") + 7, result.find("\nPhone Number: ") - (result.find("Email: ") + 7));
                phoneNumber = result.substr(result.find("Phone Number: ") + 15);

                firstName[0] = toupper(firstName[0]);
                lastName[0] = toupper(lastName[0]);
                lastName[lastName.find("_") + 1] = toupper(lastName[lastName.find("_") + 1]);
                for (int i = 0; i < email.length(); i++)
                {
                    if (isalpha(email[i]))
                    {
                        email[i] = tolower(email[i]);
                    }
                
                }
                isDataEntered = true;
            } else {
                cout << error << endl;
            }
        }
        else if (input.substr(0, 3) == "bio") {
            string bio = validateBio(input, error);
            if (!bio.empty()) {
                cout << "bio saved successfully" << endl;
                bioDescription = bio;
                bioCompleted = true;
            } else {
                cout << error << endl;
            }
        }

        if (bioCompleted) {
            analyzeBio(bioDescription);
            analyzePhone(phoneNumber);
            cout << "----------" << endl;
            cout << firstName << " " << lastName << endl;
            cout << "Email: " << email << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << endl;
            cout << "Biography:" << endl;
            cout << bioDescription << endl;
            cout << "----------" << endl;
            break;
        }
    }
    return 0;
}



