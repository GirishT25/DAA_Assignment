#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

bool containsUpper(const string &password)
{
    for (char ch : password)
        if (isupper(ch))
            return true;
    return false;
}

bool containsLower(const string &password)
{
    for (char ch : password)
        if (islower(ch))
            return true;
    return false;
}

bool containsDigit(const string &password)
{
    for (char ch : password)
        if (isdigit(ch))
            return true;
    return false;
}

bool containsSpecial(const string &password)
{
    string specialChars = "!@#$%^&*()-+";
    for (char ch : password)
        if (specialChars.find(ch) != string::npos)
            return true;
    return false;
}

bool isCommonPassword(const string &password)
{
    unordered_set<string> commonPasswords = {"123456", "password", "123456789", "qwerty", "abc123"};
    return commonPasswords.find(password) != commonPasswords.end();
}


string suggestStrongPassword(string password)
{
    string specialChars = "!@#$%^&*()-+";
    if (!containsUpper(password))
        password += 'A';
    if (!containsLower(password))
        password += 'a';
    if (!containsDigit(password))
        password += '1';
    if (!containsSpecial(password))
        password += specialChars[0];
    while (password.length() < 8)
    {
        password += 'x'; 
    }
    if (isCommonPassword(password))
    {
        password += specialChars[1]; 
    }

    return password;
}

int main()
{
    string userPassword;
    cout << "Enter your password: ";
    cin >> userPassword;

    string strongPassword = suggestStrongPassword(userPassword);
    cout << "Suggested Strong Password: " << strongPassword << endl;

    return 0;
}