//
// Created by Tiz Gonzalez on 2/4/17.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double UNIT_SPOOL_COST = 100.00,
        SHIPPING_CHARGE = 10.00;

//function prototypes
void getOrderInfo(int &, int &, double &);

void displayStatus(int, int, double = SHIPPING_CHARGE);


int main() {
    int numOrdered = 0,      //Number of spool's ordered
            inStock = 0;         //Number of spool's in stock
    double specialCharges = 0.0; //Special charges(if applied)


    getOrderInfo(numOrdered, inStock, specialCharges);

    if (specialCharges >= 10)
        displayStatus(numOrdered, inStock, SHIPPING_CHARGE + specialCharges);
    else
        displayStatus(numOrdered, inStock);

    return 0;

} //end of main function

void getOrderInfo(int &ord, int &stock, double &specChg) {
    cout << "How many spools were ordered? ";
    cin >> ord;
    while (ord < 1) {
        cout << "The number of spools ordered must be one or more. "
             << "Please re-enter";
        cin >> ord;
    }

    cout << "How many spools are in stock? ";
    cin >> stock;
    while (stock < 0) {
        cout << "The number of spools in stock must be zero or more"
             << "Please enter again. ";
        cin >> stock;
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "\nAmount of the special shipping charges (per spools)\n"
         << "above the regular $" << SHIPPING_CHARGE
         << " per spool rate (0 for none): ";
    cin >> specChg;

    while (specChg < 0.0) {
        cout << "The extra shipping charges must be zero or more. "
             << "Please re-enter:  ";
        cin >> specChg;
    }

} //end of getOrderInfo function
//The second function receives as arguments any values needed to compute and display the following information:
//# of spools ready to ship from current stock,
//# of ordered spools on backorder (if ordered > in stock),
//Total sales price of portion ready to ship (# of spools ready to ship X $100),
//Total shipping and handling charges on the portion ready to ship,
//        Total of the order ready to ship.

void displayStatus(int ordered, int Stock, double shippingCharge) {
    int backOrder = 0;
    int shipping = 0;
    double spoolCharge = 0;
    double totalShippingCharge = 0;

    if (ordered > Stock) {
        backOrder = ordered - Stock;
        shipping = Stock;
    } else {
        shipping = ordered;
    }

    spoolCharge = shipping * UNIT_SPOOL_COST;
    totalShippingCharge = shipping * SHIPPING_CHARGE;

    cout << "*** Order Summary ***\n\n ";
    cout << "Spools ordered :  " << ordered << endl;
    cout << " Spools in this shipment : " << shipping << endl;
    cout << " Spools back ordered : " << backOrder;
    cout << "\n\nCharges for this shipment \n";
    cout << "-------------------------\n";
    cout << " Spool charges: "<< setw(7)<< "$" << setw(11) << spoolCharge << endl;
    cout << " Shipping charges: " << setw(4)<< "$" << setw(11) << totalShippingCharge << endl;
    float total = (float) (spoolCharge + totalShippingCharge);
    cout << " Total this shipment "<< setw(2)<< "$" << setw(11) << total;
}