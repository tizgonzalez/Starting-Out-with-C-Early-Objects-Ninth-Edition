
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
//Tizania S. Gonzalez
//submitted on March 7, 2017
//this program grades the written portion of a Department of Motor Vehicles
// (DMV) driver's license exam.
//  The exam has 20 multiple choice questions.
using namespace std;

const int SIZE = 20;

//the class name is called TestGrader
class TestGrader {
private:
    char answers[SIZE];
//we need two functions that take the correct answers and the user answers
public:
    void setKey(char[]);

    void grade(char[]);
};

//setkey receives a 20-character string holding the correct answers and copies this
// information into its answers array.
void TestGrader::setKey(char key[]) {
//    if (key.length() != SIZE) {
//        cout << "Error in key data. \n";
//        return;
//    }
    for (int index = 0; index < SIZE; index++) {
        answers[index] = key[index];
    }
};

//grade checks for right and wrong answers
void TestGrader::grade(char userAnswers[]) {
    int right_answer = 0;
    int wrong_answer = 0;
    string wrong_answers[SIZE];

    for (int question_number = 0; question_number < SIZE; question_number++) {
        if (userAnswers[question_number] == answers[question_number]) {
            right_answer += 1;
        } else if (userAnswers[question_number] != answers[question_number]) {
            wrong_answers[wrong_answer] = to_string(question_number + 1);
            wrong_answer += 1;
        }
    }
//if right answers from user is more or equal than 15 than they passed. less they fail
    if (right_answer >= 15) {
        cout << '\n';
        cout << "Congratulations. You passed the exam. " << '\n';
        cout << endl;
    } else {
        cout << '\n';
        cout << "Sorry. You failed the exam. " << '\n';
        cout << endl;
    }
//this prints out the number of right answers
    cout << "You got " << right_answer << " questions correct. " << "\n";
//this prints the number of missed answers as well as the questions of the missed answers
    cout << "You missed the following " << wrong_answer << " questions: ";
    for (int index = 0; index < wrong_answer; index++)
    {
         cout << wrong_answers[index] << " ";
    }
};

//main holds the array with the right answers. it also ask for user to enter their name
//and enter the answer
int main() {
    TestGrader grader;
    char userAnswers[SIZE];
    char answers[SIZE] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B',
                          'D', 'A'};
    string name;
    char anotherTest;

    grader.setKey(answers);

    do {
        cout << "Applicant's Name: ";
        getline(cin, name);
        cout << "\nEnter answers for " << name << ".\n";
        cout << "\nUse only letters A, B, C, and D.\n\n";
//user needs to enter a valid answer if not it will ask to enter a valid answer
        for (int index = 0; index < SIZE; index++) {
            cout << "Q " << index + 1 << ": ";
            cin >> userAnswers[index];
            userAnswers[index] = toupper(userAnswers[index]);
            while (userAnswers[index] != 'A' && userAnswers[index] != 'B'
                   && userAnswers[index] != 'C' && userAnswers[index] != 'D') {
                cout << "Please enter a valid answer.";
                cin >> userAnswers[index];
                userAnswers[index] = toupper(userAnswers[index]);
            }
        }
        grader.grade(userAnswers);
//this ask user to enter another exam if needed if not it ends
        cout << "\n\nGrade another exam (Y/N)? ";
        cin >> anotherTest;
        while (toupper(anotherTest) != 'Y' && toupper(anotherTest) != 'N') {
            cout << "Please enter a valid option.";
            cin >> anotherTest;
        }
    } while (toupper(anotherTest) == 'Y');

    return 0;
};