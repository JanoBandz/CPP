#include <iostream>
#include "Banking.h"

using namespace std;

Banking::Banking() {
	m_initialInvestment = 0.0;
	m_monthlyDeposit = 0.0;
	m_interestRate = 0.0;
	m_numYears = 0;
}

void Banking::setInitialInvestment(double t_initialInvestment) { m_initialInvestment = t_initialInvestment; }
void Banking::setMonthlyDeposit(double t_monthlyDeposit) { m_monthlyDeposit = t_monthlyDeposit; }
void Banking::setInterestRate(double t_interestRate) { m_interestRate = t_interestRate;  }
void Banking::setNumYears(int t_numYears) { m_numYears = t_numYears; }

void Banking::displayBalances() {
	double currentBalance = m_initialInvestment;
	double yearlyInterest = 0;

	cout << "Year\tYear End Balance\tYear End Interest" << endl;
	cout << "----------------------------------------------------------" << endl;

	//calculation loop
	for (int i = 1; i <= m_numYears; i++) {
		yearlyInterest = 0;

		for (int j = 1; j <= 12; j++) {
			//calculate monthly interest
			double monthlyInt = (currentBalance + m_monthlyDeposit) * ((m_interestRate / 100.0 / 12.0));
			yearlyInterest += monthlyInt;
			currentBalance = currentBalance + m_monthlyDeposit + monthlyInt;
		}

		//years results
		cout << i << "\t$" << currentBalance << "\t\t$" << yearlyInterest << endl;
	}

}