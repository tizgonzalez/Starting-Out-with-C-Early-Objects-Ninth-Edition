//Programming assignment #3
//This program uses a population class (pop) that calculate the birth and death rates
// Created by Tiz Gonzalez on 2/21/17.
//

#include <iostream>
#include <iomanip>


using namespace std;

class Pop
{
    private:
        long population; //current  population
        int numBirths,   //annual number of births
            numDeaths;   //annual number of deaths
    public:
        Pop();
        Pop(long, int, int);

        void setPopulation(long p);
        void setBirths(int b);
        void setDeaths(int d);

        long getPopulation()
        {
            return population;
        };

        double getBirthRate()
        {
            return double (numBirths) / population;
        }

        double getDeathRate()
        {
            return double (numDeaths) / population;
        }
};

Pop::Pop() {
    population = 0;
    numBirths = 0;
    numDeaths = 0;
}

Pop::Pop(long p, int b, int d) {
    setPopulation(p);
    setBirths(b);
    setDeaths(d);
}


void Pop::setPopulation(long p) {
    if (p >= 2)
        population = p;
    else
        population = 2;
}

void Pop::setBirths(int b) {
    if (b >= 0)
        numBirths = b;
    else
        numBirths = 0;
}

void Pop::setDeaths(int d) {
    if (d >= 0)
        numDeaths = d;
    else
        numDeaths = 0;
}


int main()
{
    Pop  cityOfAustin;
    long numPeople;
    int numBirths,
        numDeaths;

    cout << "Enter total population: "; //ask for a value of population
    cin >> numPeople;

    while (numPeople < 1) //this validates that you put a number higher than 0
    {
        cout << "Value must be higher than 0. Please enter total population: ";
        cin >> numPeople;
    }

    cityOfAustin.setPopulation(numPeople);

    cout << "Enter annual number of births: "; //ask user for births
    cin >> numBirths;

    while (numBirths < 0) //this validates that you put a number higher than 0
    {
        cout << "Value cannot be negative. Please re-enter: ";
        cin >> numBirths;
    }

    cityOfAustin.setBirths(numBirths);

    cout << "Enter annual number of deaths: "; //ask user for deaths
    cin >> numDeaths;

    while (numDeaths < 0) //this validates that you put a number higher than 0
    {
        cout << "Value cannot be negative. Please re-enter: ";
        cin >> numDeaths;
    }

    cityOfAustin.setDeaths(numDeaths);

    cout << "\nPopulation Statistics in Austin \n"; //this prints it out nicely
    cout << fixed << showpoint << setprecision(3);
    cout << "\n\tPopulation:   " << setw(7) << cityOfAustin.getPopulation();
    cout << "\n\tBirth Rate:   " << setw(7) << cityOfAustin.getBirthRate();
    cout << "\n\tDeath Rate:   " << setw(7) << cityOfAustin.getDeathRate() << endl;

    return 0;
}