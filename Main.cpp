/*Jonathan Ayala
* CS210
* February 4 2026
*/

#include <iostream>
#include <string>
#include "Banking.h"

using namespace std;

int getInteger(int lowest);
int getInteger(int lowest, string prompt);
double getDouble(int lowest, string prompt);

int main() {

	Banking airgead;

	int numYears = 0; // num of years
	double
		initialInvestment = 0.0,
		monthlyDeposit = 0.0,
		interestRate = 0.0,
		beiginningBalance = 0.0,
		interest = 0.0,
		closingBalance = 0.0;

	initialInvestment = getDouble(0, "what is the initial investment? ");
	airgead.setInitialInvestment(initialInvestment);

	monthlyDeposit = getDouble(0, "what is the monthly deposit? ");
	airgead.setMonthlyDeposit(monthlyDeposit);

	interestRate = getDouble(1, "what is interest rate? ");
	airgead.setInterestRate(interestRate);

	numYears = getInteger(1, "how many years should the investment grow? ");
	airgead.setNumYears(numYears);

	airgead.displayBalances(); //display and calculates the balances

	return 0;
}

int getInteger(int lowest)
{
	int number = 0; // return number
	bool needData = true;

	do {
		cout << "Enter a number greater than or equal to " << lowest << " ";
		cin >> number;
		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}
	} while (needData);

	return number;
}

int getInteger(int lowest, string prompt)
{
	int number = 0;
	bool needData = true;

	do {
		cout << prompt;
		cin >> number;
		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << (lowest) << endl;
		}
	} while (needData);

	return number;
}

double getDouble(int lowest, string prompt)
{
	double number = 0.0;
	bool needData = true;

	do {
		cout << prompt;
		cin >> number;
		needData = (number < lowest);
		if (needData) {
			cout << "Invalid number - must be greater than or equal to " << lowest << endl;

		}
	} while (needData);

	return number;
}