//Programming assignment 5
//Tizania S. Gonzalez
//Program created on 3/23/2017
//This Program sorts an array of strings and organizes it in alphabetical order. It also does a binary search for two names
// and determines if the names were found or not.
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//function prototype that takes two parameters
void selectionSort(string [], int);
//function prototype that takes four parameters
void searchList(string, string, string [], int);

//main function that has the driver
int main()
{
    const int SIZE = 20; //constant size of array
    string names[SIZE] = {"Collins, Bill","Smith, Bart","Michalski, Joe",
                          "Griffin, Jim","Sanchez, Manny", "Rubin, Sarah",
                         "Taylor, Tyrone","Johnson, Jill","Allison, Jeff",
                         "Moreno, Juan", "Wolfe, Bill","Whitman, Jean","Moretti, Bella",
                         "Wu, Hong","Patel, Renee","Harrison, Rose","Smith, Cathy",
                         "Conroy, Pat","Kelly, Sean","Holland, Beth" };
    string name,
    displayName;
    //this displays the values
    selectionSort(names, SIZE);

    //names i am searching for for
    //display name is the name it should display, name is the one in the array
    displayName = "Bill Wolfe";
    name = "Wolfe, Bill";

    searchList(displayName, name, names, SIZE);

    displayName = "Wilbur the Pig";
    name = "Pig, the Wilbur";

    searchList(displayName, name, names, SIZE);


    return 0;

};

//function displays names in alphabetical order that takes two parameters
void selectionSort(string array[], int size)
{
    int startScan, minIndex;
    string minValue;
//iterates through the array
    for(int startScan = 0; startScan < (size - 1); startScan++)
    {
            minIndex = startScan;
            minValue = array[startScan];
            for (int index = startScan + 1; index < size; index++)
            {
                string firstName = minValue; //first value
                string secondName = array[index]; //second value
                int charIndex = 0;
                while (firstName[charIndex] == secondName[charIndex]) //while the letters are the same, keep checking until it is different
                {
                    charIndex++;
                }
                if (secondName[charIndex] < firstName[charIndex])
                {
                    minValue = array[index];
                    minIndex = index;
                }
            }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    cout << "The names in sorted order are: \n\n"; //prints out the names in order
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

//a binary search function that takes four parameters
void searchList(string name, string value, string names[], int size)
{   //prints out the name on the array
    cout << "\nSearching for " << name << "...\n";

    int first = 0, //first array
            last = size - 1, //last array
            middle, //middle array
        position = -1; //position of the search value
    bool found = false; //flag

    while (!found && first <= last)
   {
       middle = (first + last) /2;//calculates midpoint
       if(names[middle]== value) //if value is found at midpoint
       {
           found = true;
           position = middle;
       }
       else if (names[middle] > value) //if position is lower half
       {
           last = middle -1;
       }
       else {
           first = middle + 1; //if position is in upper half
       }
   }
    if (position == -1) //if name is not found
        cout << "That name does not exist in the array.\n";
    else
    {
        cout << name << " was found in the array. \n "; //if name is found
    }

}