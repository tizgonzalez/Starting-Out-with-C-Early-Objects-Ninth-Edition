//
// Created by Tizania Gonzalez
// Lab Assignment 1
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string Runner1, Runner2, Runner3;
    float Time1, Time2, Time3;
    cout << "Enter the names of three runners and their finishing times.\n";
    cout << "Then I will tell you who came in first, second, and third.\n\n";


    cout << "Name of Runner 1: ";
    getline(cin, Runner1);
    cout << "Runner 1's finishing time: ";
    cin >> Time1;
    cin.ignore();

    cout << "\nName of Runner 2: ";
    getline(cin, Runner2);
    cout << "Runner 2's finishing time: ";
    cin >> Time2;
    cin.ignore();

    cout << "\nName of Runner 3: ";
    getline(cin, Runner3);
    cout << "Runner 3's finishing time: ";
    cin >> Time3;
    cin.ignore();

    cout << "\nRunner 1: ";
    cout << Runner1 << endl;
    cout << "Time 1: ";
    cout <<  Time1 << endl;

    cout << "\nRunner 2: ";
    cout << Runner2 << endl;
    cout << "Time 2: ";
    cout <<  Time2 << endl;

    cout << "\nRunner 3: ";
    cout << Runner3 << endl;
    cout << "Time 3: ";
    cout <<  Time3 << endl;

    cout << "\n";

    if (Time1 <= 0  ||  Time2 <= 0 || Time3 <= 0 )
        cout << "Runner times cannot be less than or equal to 0.\n";
    else
    {
        cout << "Race results \n";
        cout << "-------------\n\n";
        cout << fixed << showpoint << setprecision(2);

        cout << "1st place: ";
        if((Time1 < Time2) && (Time1 < Time3))
            cout << left << setw(10) << Runner1 << " "
                 << right << setw(5) << Time1 << endl;
        else if (Time2 < Time3)
            cout << left << setw(10) << Runner2 << " "
                 << right << setw(5) << Time2 << endl;
        else
            cout << left << setw(10) << Runner3 << " "
                 << right << setw(5) << Time3 << endl;

        cout << "2nd place: ";
        if(((Time1 > Time2) && (Time1 < Time3)) or ((Time1 < Time2) && (Time1 > Time3)))
        cout << left << setw(10) << Runner1 << " "
             << right << setw(5) << Time1 << endl;
        else if (((Time2 > Time1) && (Time2 < Time3)) or ((Time2 < Time1) && (Time2 > Time3)))
            cout << left << setw(10) << Runner2 << " "
                 << right << setw(5) << Time2 << endl;
        else
            cout << left <<setw(10) << Runner3 << " "
                 << right << setw(5) << Time3 << endl;

        cout << "3rd place: ";
        if ((Time1 > Time2) && (Time1 > Time3))
            cout << left << setw(10) << Runner1 << " "
                 << right << setw(5) << Time1 << endl;
        else if (Time2 > Time3)
            cout << left <<setw(10) << Runner2 << " "
                 << right << setw(5) << Time2 << endl;
        else
            cout << left <<setw(10) << Runner3 << " "
                 << right << setw(5) << Time3 << endl;

    }


    return 0;


}

