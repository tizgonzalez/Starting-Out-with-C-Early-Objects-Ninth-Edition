//Tizania S. Gonzalez
// Chapter 11 - Assignment 1, Check Writing
// This program creates a Number Translation class
// That can be used for writing checks.
#include <iostream>

using namespace std;
//set a class called Numbers
class Numbers {

private:
    int number;

    static string one[]; //set a static string array
    static string twenty[];//set a static string array

public:
    Numbers();

    Numbers(int num) { setNum(num); };

    void setNum(int num) { number = num; };

    void print();

};

string Numbers::one[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                         "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                         "seventeen", "eighteen", "nineteen"};
string Numbers::twenty[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void Numbers::print() {
    int num;

    if (number == 0) {    //checks if number is 0
        cout << one[number] << " ";
    } else {
        if (number <= 9999 && number >= 1000) {    //if number is between 1000 and 9999
            num = number / 1000;
            number %= 1000;
            cout << one[num] << " thousand ";
        }
        if (number < 1000 && number >= 100) {     //if number is between 100-1000
            num = number / 100;
            number %= 100;
            cout << one[num] << " hundred ";
        }
        if (number < 100 && number >= 20) {     //if number is between 20-100
            num = number / 10;
            number %= 10;
            cout << twenty[num - 2] << " ";
        }
        if (number < 20 && number > 0) {        //if number is between 0-20
            cout << one[number] << " ";
        }
    }
    if (number == 1) {        //if number is 1 then print dollar
        cout << "dollar";
    } else {
        cout << "dollars";    //else print dollars
    }
}


int main() {
    // Tell user what the program does and get input
    cout << "This program translates whole dollar amounts into words ";
    cout << "for the purpose of writing checks.";
    cout << "\nEntering a negative terminates the program.";
    cout << "\nEnter an amount for be translated into words: ";
    int number;
    cin >> number;

    // Keep translating numbers until the user enters a negative value
    while (number >= 0) {
        // Create a Numbers object
        Numbers n(number);
        // Print the English description
        n.print();
        // Get another number
        cout << "\nEnter another number: ";
        cin >> number;
    }

    // We are done
    return 0;
}