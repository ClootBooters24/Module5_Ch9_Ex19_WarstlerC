//Lab9-2.cpp - displays two monthly car payments

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);



int main()
{
	int carPrice = 0;
	int rebate = 0;
	double creditRate = 0.0;
	double dealerRate = 0.0;
	int term = 0;
	double creditPayment = 0.0;
	double dealerPayment = 0.0;

	cout << "Car price (after any trade-in): ";
	cin >> carPrice;
	cout << "Rebate: ";
	cin >> rebate;
	cout << "Credit union rate: ";
	cin >> creditRate;
	cout << "Dealer rate: ";
	cin >> dealerRate;
	cout << "Term in years: ";
	cin >> term;

//call function to calculate payments
	creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
	dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

//display payments
	cout << fixed << setprecision(2) << endl;
	cout << "Credit union payment per month: $" << creditPayment << endl;
	cout << "Credit union payment total: $" << (creditPayment * term) << endl;
	cout << "Dealer payment per moth: $" << dealerPayment << endl;
	cout << "Dealer payment total: $" << (dealerPayment * term) << endl;
	return 0;

}//end of main function

//function definitions
double getPayment(int prin, double monthRate, int months)
{
	double denom = (1 - pow(monthRate + 1, -months));
	if (denom == 0)
	{
		return -1;
	}
//calculates and returns a monthly payment
	double monthPay = 0.0;
	monthPay = prin * monthRate / denom;
	return monthPay;

} //end of getPayment function
