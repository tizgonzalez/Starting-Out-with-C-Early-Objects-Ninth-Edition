//Tizania S. Gonzalez
//date completed was 04/01/2017
//This program dynamically allocates an array large enough to hold a user-defined number of test scores. Once all
//the scores are entered , the array should be passed to a function that sorts them in ascending order.
//it should also calculate an average.
#include <iostream>
#include <algorithm>
using namespace std;

//declare a function protoype that holds an array and a size
float average(float score[ ], int size);
int main() {
    //global variables
    int numberOfScores;
    float *testScores;
    float ave;

    //have user enter number of scores
    cout << "Enter number of scores";
    cin >> numberOfScores;
    testScores = new float[numberOfScores]; //dynamically allocate memory

    //get the test scores for each score using Pointers
    cout << "Enter the " << numberOfScores << " scores separated by space";
    float *p = testScores;
    for (int k = 0; k < numberOfScores; k++) {
        cin >> *p;
        if (*p <0)
        {
            cout <<"You may not use negative numbers";
            exit(0);
        }
        p++;
    }

    //Echo scores back to user
    cout << "Scores entered:\n";
     p = testScores;
    for (int j = 0; j < numberOfScores; j++)
    {
        cout << *p << " "; p++;
    }

    //sort scores using STL algorothim sort library
    sort(testScores, testScores+ numberOfScores);
    //compute average
    ave = average(testScores, numberOfScores);

    //print the output
    cout << "\nThe list of sorted scores is\n";
    p = testScores;
    for (int m = 0; m < numberOfScores; m++)
    {
        cout << *p << " "; p++;
    }
    cout << "\nThe average is: "<< ave << endl;
    cout << "----------------------------";
    delete testScores;
    return 0;
}
//calculate the average of the scores
float average(float a[ ], int size)
{
    float sum = 0;
    float *p = a; //pointer to next array entry to be summed
    for (int k = 0; k < size; k++)
    {
        sum = sum + *p;
        p ++;
    }
    return sum/size;
}