// Author:             Tizania Gonzalez & Tanya Garduno
// Assignment Number:  Lab 9 Converting a python hangman game to a c++
// File Name:          L<lab number>_<lastname>.cpp
// Course/Section:     COSC 1337 Section <your section number here>
// Date:               4/30/2017
// Instructor:         Bernard, Ku


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;
void HangPerson(int);
bool Quit = false;
char Answer;


int main()

{
    const int MAX_WRONG = 6;   //maximum attempts
    vector<string> words;    //we will add our words here
    words.push_back ("PIZZA");
    words.push_back ("BACON");
    words.push_back ("COFFEE");
    words.push_back ("CAT");
    words.push_back ("DOG");
    words.push_back ("SUMMER");
    words.push_back ("BERNARD");
    words.push_back ("AUSTIN");
    words.push_back ("RABBITS");


    srand (static_cast<unsigned int>(time (0)));
    random_shuffle (words.begin (), words.end ());
    const string WORD_TO_GUESS = words[0];  //this is the words we need to guess
    string soFar (WORD_TO_GUESS.size (), '-');   //this string contains -
    string used = "";
    int wrong = 0; //to count wrong letters

    string name;
    cout << "Please enter your name: \n";
    cin >> name;
    cout << "Welcome " << name << ", to Hang-man. Let's play! \n";
    cout << name << ", you have " << (MAX_WRONG - wrong) << " more guesses.\n";

    //main game loop
    while ((wrong < MAX_WRONG) && (soFar != WORD_TO_GUESS)) {
        cout << "Letters Used: " << used << endl;
        cout << "Guessing Word: " << soFar << endl;
        HangPerson (wrong);
        //user enters guess so far
        char guess;
        cout << "Guess a letter: \n";
        cin >> guess;
        guess = toupper (guess);


        //while user enters a letter he already used
        while (used.find (guess) != string::npos) {
            cout << "\nYou have already guessed  " << guess << endl;
            cout << "Enter another guess: \n";
            cin >> guess;
            guess = toupper (guess);

        }

        used += guess;
        HangPerson (wrong);

        if (WORD_TO_GUESS.find (guess) != string::npos) {
            cout << "Correct " << guess << " is in the word!\n";
            for (unsigned int i = 0; i < WORD_TO_GUESS.length (); i++) {

                if (WORD_TO_GUESS[i] == guess)
                    soFar[i] = guess;
            }


        } else {
            ++wrong;
            cout << guess << " is not in the word.\n";
            cout << "You have " << (MAX_WRONG - wrong) << " guesses left.\n";
        }

    }
    HangPerson (wrong);

    if (wrong == MAX_WRONG) {
        cout << "\nGame over, you have been hanged!\n";
    } else {
        cout << name << ", you guessed it, you win!\n";
    }


    cout << "\n\nThe word was: " << WORD_TO_GUESS << endl;
    //here i should add the function that ask user to play again

    while (!Quit)
    {
        char guess;
        //your code here

        std::cout << "Would you like to quit?  (Y or N) \n" << std::endl;
        std::cin >> Answer;

        while (Answer == 'n' || Answer =='N')

        {
            cout << "Let's play again! \n";
            main ();
        }
        if (Answer == 'Y' || Answer == 'y')

        {
            Quit = true;
        }
        return 0;
    }
}

//Drawing of the Hang man here
void HangPerson(int state) {
    if (state == 6) {

        cout << endl << endl
             << "   +----+     " << endl
             << "   |    |     " << endl
             << "   |    O     " << endl
             << "   |   /|\\   " << endl
             << "   |   / \\   " << endl
             << "   |You're Dead! " << endl
             << "  ==============" << endl << endl;
    } else if (state == 5) {
        cout << endl << endl
             << "   +----+  " << endl
             << "   |    |  " << endl
             << "   |    O  " << endl
             << "   |   /|\\ " << endl
             << "   |     \\ " << endl
             << "   |       " << endl
             << "  ============" << endl << endl;
    } else if (state == 4) {
        cout << endl << endl
             << "   +----+  " << endl
             << "   |    |  " << endl
             << "   |    O  " << endl
             << "   |   /|\\ " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "  =============" << endl << endl;
    } else if (state == 3) {
        cout << endl << endl
             << "   +----+  " << endl
             << "   |    |  " << endl
             << "   |    O  " << endl
             << "   |   /|  " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "  =============" << endl << endl;
    } else if (state == 2) {
        cout << endl << endl
             << "   +----+  " << endl
             << "   |    |  " << endl
             << "   |    O  " << endl
             << "   |    |  " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "  =============" << endl << endl;
    } else if (state == 1) {
        cout << endl << endl
             << "   +----+  " << endl
             << "   |    |  " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "   |       " << endl
             << "  =============" << endl << endl;
    }

}