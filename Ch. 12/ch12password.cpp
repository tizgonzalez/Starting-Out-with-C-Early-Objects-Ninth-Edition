//Tizania S. Gonzalez
//Ch 12 #10, pg. 850
//Date Completed 4-27-2017
//Password Verifier-software package that requires users to enter their own passwords.
//Our software requires that user’s passwords meet a following criteria



#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//function prototype
string enterPassword();

//function that returns the users password
string enterPassword()
{   string p;
    cout << "Enter password or (Q to quit) : ";
    cin >> p;
    return p;
}
//main function
int main() {
    const int MIN_LENGTH = 6;
    string password;
    int upper, lower, digit;

    // Ask user to create a password
    cout << "Create your password\n"
         << "passwords must meet the following criteria:\n"
         << " • The password should be at least six characters long.\n"
         << " • The password should contain at least one uppercase\n"
         << "   and at least one lowercase letter.\n"
         << " • The password should have at least one digit.\n";
    //calls the function
    password = enterPassword();

//verifies if password is not Q then it will execute
    while (password != "Q" && password != "q") {
        //sets variables to zero
        upper = 0;
        lower = 0;
        digit = 0;

//this will look at each letter entered and check if it is Upper Lower or Digit
        for (int i = 0; i < password.length(); i++) {
            if (isupper(password[i]))
                upper++;
            else if (islower(password[i]))
                lower++;
            else if (isdigit(password[i]))
                digit++;
        }
//if it equals to zero then it will display what it is missing
        if (password.length() < MIN_LENGTH)
            cout << "password is not at least six characters long.\n";
        else if (upper == 0)
            cout << "password does not contain at least one uppercase letter.\n";
        else if (lower == 0)
            cout << "password does not contain at least one lowercase letter.\n";
        else if (digit == 0)
            cout << "password does not have at least one digit.";
        else
            cout << "Password verified. Your password is: " << password << "\n";
//calls function again
        password = enterPassword();
    };

    return 0;
}