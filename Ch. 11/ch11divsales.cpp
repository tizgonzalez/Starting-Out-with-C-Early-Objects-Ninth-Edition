//Tizania S. Gonzalez
//date completed was 04/18/2017
//This program has 6 divisions that have 4 quarters. The user will enter sales for each division. After entered, it
//should display the sales plus the total sales for that year.
#include <iostream>
#include <iomanip>
using namespace std;


class DivSales //class that keeps sales data for a division
{
private:
    double sales[4];      //there are 4 quarterly sales
    static double totalSales; //total sales for an entire year
public:
    void setSales(double, double, double, double);
    double getQSales(int);
    static double getCorpSales()
    { return totalSales; }

};


//set sales from each division and computes total sales

void DivSales::setSales(double q1, double q2, double q3, double q4)
{
    sales[0] = q1;
    sales[1] = q2;
    sales[2] = q3;
    sales[3] = q4;

    //adds the quarterly sales to get the total

    totalSales+= q1+q2+q3+q4;


}

double DivSales::getQSales(int q)
{
    double value = sales[q];
    return value;
}

// It Only accepts non-negative values for quarterly sales figures.
void error()

{
    system("cls");
    cout <<"ERROR: Only provide positive values for sales \n";
    exit(0);

}

//static member variable definition
double DivSales::totalSales;

//main function
int main()
{
    const int NUM_DIV = 6;    //number of divisions
    DivSales DivisionSale[NUM_DIV];  // 6 division with each of their own array
    int quarter, division;
    for (division = 0; division < 6; division++)
    {
        double Quarter;
        double q1, q2, q3, q4;
        cout << "Enter Sales of Division: " << division + 1 << endl;

        cout << "Enter the sales total for quarter 1: ";
        cin >> q1;
        Quarter = q1;
        if (Quarter < 0)
            error();

        cout << "Enter the sales total for quarter 2: ";
        cin >> q2;
        Quarter = q2;
        if (Quarter < 0)
            error();

        cout << "Enter the sales total for quarter 3: ";
        cin >> q3;
        Quarter = q3;
        if (Quarter < 0)
            error();

        cout << "Enter the sales total for quarter 4: ";
        cin >> q4;
        Quarter = q4;
        if (Quarter < 0)
            error();

        DivisionSale[division].setSales(q1,q2,q3,q4);

    }



    // Display the budget for each division
    cout << endl;
    cout << std::setw(2);
    cout << "\t\t" << "Quarter 1 " << "\t\t" << "Quarter 2" << "\t\t" << "Quarter 3" << "\t\t" << "Quarter 4" << endl;

    // table for quarterly sales of each division
    for (division = 0; division < 6; division++)

    {
        cout << "Division " << division + 1;
        for (quarter = 0; quarter < 4; quarter++)

        {
            // calling function Sales 6 times
            cout << setprecision(2) << fixed << showpoint;
            cout << std::setw (2);
            cout << "\t$" << DivisionSale[division].getQSales(quarter);
        }

        cout << endl;

    }
    // The program should then display the total corporate sales for the year.

    cout << "-----------------------------------------------------------\n";
    cout << "\n Total Corporate Sales: ";
    cout << "$" << DivisionSale[0].getCorpSales() << endl;
    return 0;
}

