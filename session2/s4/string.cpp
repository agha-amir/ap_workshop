#include <iostream>
#include <string>
#include <regex>
#include <cstring>
using namespace std;


bool validateFlags(string& str, string* flags, int flagCount, string &error) {
    for (int i = 0; i < flagCount; i++) {
        int subStringCount = 0;
        int dashCount = 0;
        string subString = flags[i];
        size_t position = str.find(subString);
        size_t dashPosition = str.find("-");
        while (position != string::npos) {
            subStringCount += 1;
            position = str.find(subString, position + subString.length());
        }

        while (dashPosition != string::npos) {
            dashCount += 1;
            dashPosition = str.find("-", dashPosition + 1);
        }

        if (subStringCount > 1 || subStringCount == 0 || dashCount != flagCount) {
            error = "wrong flag format";
            return false;
        }
    }

    return true;
}

bool validateCommand(string& str, string &error) {
    if (str.substr(0, 8) != "register" && str.substr(0, 4) != "data" && str.substr(0, 3) != "bio") {
        error = "invalid command";
        return false;
    }

    return true;
}

bool validateRegister(string& str, string &error) {
    regex multipleSpacesPattern("\\s+");
    str = regex_replace(str, multipleSpacesPattern, " ");

    string username, password;
    regex Usernamepattern("^[a-zA-Z0-9]+([._]?[a-zA-Z0-9]+)*$");
    regex upperLowerPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*()\\-+=]).+$");
    regex consecutivePattern("([a-zA-Z0-9])\\1\\1\\1");
    size_t Uposition = str.find("-u ");
    size_t Pposition = str.find("-p ");

    if (Uposition < Pposition) {
        username = str.substr(Uposition + 3, Pposition - (Uposition + 3) - 1);
    } else {
        username = str.substr(Uposition + 3);
        size_t spacePosition = username.find(" ");
        if (spacePosition != string::npos) {
            username = username.substr(0, spacePosition);
        }
    }

    if (!regex_match(username, Usernamepattern)) {
        error = "invalid username format";
        return false;
    }

    if (Pposition < Uposition) {
        password = str.substr(Pposition + 3, Uposition - (Pposition + 3) - 1);
    } else {
        password = str.substr(Pposition + 3);
        size_t spacePosition = password.find(" ");
        if (spacePosition != string::npos) {
            password = password.substr(0, spacePosition);
        }
    }

    if (password.length() < 6 || password.length() > 20) {
        error = "weak password";
        return false;
    }

    if (!regex_match(password, upperLowerPattern)) {
        error = "weak password";
        return false;
    }

    string sub;
    for (int i = 0; i < username.length(); i++) {
        if (isalpha(username[i])) {
            sub += username[i];
        } else {
            if (sub.length() > 3 && password.find(sub) != string::npos) {
                error = "weak password";
                return false;
            }
            sub.clear();
        }
    }
    if (sub.length() > 3 && password.find(sub) != string::npos) {
        error = "weak password";
        return false;
    }

    if (regex_search(password, consecutivePattern)) {
        error = "weak password";
        return false;
    }

    return true;
}

string validateData(string& str, string &error) {
    size_t FnPosition = str.find("-fn ");
    size_t LnPosition = str.find("-ln ");
    size_t EPosition = str.find("-e ");
    size_t PhPosition = str.find("-ph ");
    string fn, ln, email, phone;
    regex multipleSpacesPattern("\\s+");
    str = regex_replace(str, multipleSpacesPattern, " ");

    if (FnPosition != string::npos) {
        size_t nextFlagPosition = str.find("-", FnPosition + 4);
        if (nextFlagPosition != string::npos) {
            fn = str.substr(FnPosition + 4, nextFlagPosition - (FnPosition + 4));
        } else {
            fn = str.substr(FnPosition + 4);
        }
        fn.erase(0, fn.find_first_not_of(" \t\n\r\f\v"));
        fn.erase(fn.find_last_not_of(" \t\n\r\f\v") + 1);
    }

    if (LnPosition != string::npos) {
        size_t nextFlagPosition = str.find("-", LnPosition + 4);
        if (nextFlagPosition != string::npos) {
            ln = str.substr(LnPosition + 4, nextFlagPosition - (LnPosition + 4));
        } else {
            ln = str.substr(LnPosition + 4);
        }
        ln.erase(0, ln.find_first_not_of(" \t\n\r\f\v"));
        ln.erase(ln.find_last_not_of(" \t\n\r\f\v") + 1);
    }

    if (EPosition != string::npos) {
        size_t nextFlagPosition = str.find("-", EPosition + 3);
        if (nextFlagPosition != string::npos) {
            email = str.substr(EPosition + 3, nextFlagPosition - (EPosition + 3));
        } else {
            email = str.substr(EPosition + 3);
        }
        email.erase(0, email.find_first_not_of(" \t\n\r\f\v"));
        email.erase(email.find_last_not_of(" \t\n\r\f\v") + 1);
    }

    if (PhPosition != string::npos) {
        size_t nextFlagPosition = str.find("-", PhPosition + 4);
        if (nextFlagPosition != string::npos) {
            phone = str.substr(PhPosition + 4, nextFlagPosition - (PhPosition + 4));
        } else {
            phone = str.substr(PhPosition + 4);
        }
        phone.erase(0, phone.find_first_not_of(" \t\n\r\f\v"));
        phone.erase(phone.find_last_not_of(" \t\n\r\f\v") + 1);
    }

    regex FirstNamePattern("^[a-zA-Z]+$");
    regex LastNamePattern("^([a-zA-Z]+(_[a-zA-Z]+)?|[a-zA-Z]+)$");
    regex EmailPattern(R"(^([a-zA-Z0-9]+([._][a-zA-Z0-9]+)*)@([a-zA-Z0-9]+([.][a-zA-Z0-9]+)*)\.com$)");
    regex PhoneNumberPattern(R"(^(\+989[0-9]{9}|09[0-9]{9})$)");

    if (!regex_match(fn, FirstNamePattern) || !regex_match(ln, LastNamePattern)) {
        error = "wrong name format";
        return "";
    }

    if (!regex_match(email, EmailPattern)) {
        error = "invalid email format";
        return "";
    }

    if (!regex_match(phone, PhoneNumberPattern)) {
        error = "invalid phone number";
        return "";
    }

    return fn + " " + ln + "\nEmail: " + email + "\nPhone Number: " + phone;
}

string validateBio(string& str, string &error) {
    regex multipleSpacesPattern("\\s+");
    str = regex_replace(str, multipleSpacesPattern, " ");
    size_t BioPosition = str.find("bio ");
    regex descriptionPattern(R"(bio\s*\"([^\"]*)\")");

    smatch match;
    if (!regex_search(str, match, descriptionPattern)) {
        error = "invalid bio format";
        return "";
    }

    return match.str(1);
}


void analyzeBio(string& bio){

    if (bio[0] == ' ')
    {
        bio[0] = '\0';
    }
    else if (bio [bio.length()] == ' ')
    {
        bio [bio.length()] = '\0';
    }
    string reduced = regex_replace(bio, regex(R"((\\n){3,})"), "\\n\\n");
    string res = regex_replace(reduced, regex(R"(\\n)"), "\n");

    bio = res;
}

void analyzePhone(string& phone) {
    string res = "";
    regex pattern1(R"(989\d{9})");
    regex pattern2(R"(09\d{9})");

    if (regex_match(phone, pattern1))
    {
        res += "+98-9" + phone.substr(3, 2) + "-" + phone.substr(5, 3) + "-" + phone.substr(8, 4);
    }
    else{
        res += "+98-9" + phone.substr(1, 2) + "-" + phone.substr(3, 3) + "-" + phone.substr(6, 4);
    }

    phone = res;
}
