#ifndef BANKING_H
#define BANKING_H

#include <vector>

class Banking {
public:

	//constructor
	Banking();

	//setters
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setInterestRate(double t_interestRate);
	void setNumYears(int t_numYears);

	//main display method
	void displayBalances();

private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_interestRate;
	int m_numYears;

};

#endif