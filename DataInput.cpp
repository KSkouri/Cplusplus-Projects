#include <iostream>
#include "DataInput.h"
#include <iomanip>
using namespace std;

//print specified number of chars
string nCharString(size_t n, char c) {
	string charString;
	while (charString.length() < n) {
		charString = charString + c;
	}
	return charString;
}

//output menu and read input
void DataInput::PrintMenu() {

	cout << nCharString(11, '*') << " Data Input " << nCharString(11, '*') << endl;
	cout << nCharString(34, '*') << endl;
	cout << "Initial Investment Amount: " << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: " << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: " << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> numYears;

	system("pause");
}

void DataInput::DisplayWithoutDeposits(/*int initialInvestment, int annualInterest, int numYears*/) {
	int i;
	int j;
	double balance;
	double interestEarned;
	double interestRate;
	double finalInterest;

	cout << endl;
	cout << endl;
	cout << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << nCharString(64, '=') << endl;
	cout << "Year" << "\t" << "Year End Balance" << "\t" << "Year End Earned Interest" << endl;
	cout << nCharString(64, '-') << endl;

	interestRate = (annualInterest / 100) / 12;
	interestEarned = 0.0;
	finalInterest = 0.0;

	for (i = 1; i <= numYears; ++i) {
	
		for (j = 1; j <= 12; ++j) {
			interestEarned = initialInvestment * interestRate;
			balance = initialInvestment + interestEarned;
			finalInterest += interestEarned;
			initialInvestment = balance;
		}

		cout << " " << i << "\t\t" << "$";
		cout << fixed << setprecision(2) << balance;
		cout << "\t\t\t" << "$" << finalInterest << endl;
		cout << endl;

		finalInterest = 0.0;
	}
}

void DataInput::DisplayWithDeposits() {
	int i;
	int j;
	double balance;
	double interestEarned;
	double interestRate;
	double finalInterest;

	cout << endl;
	cout << endl;
	cout << "     Balance and Interest With Additional Monthly Deposits     " << endl;
	cout << nCharString(64, '=') << endl;
	cout << "Year" << "\t" << "Year End Balance" << "\t" << "Year End Earned Interest" << endl;
	cout << nCharString(64, '-') << endl;

	interestRate = (annualInterest / 100) / 12;
	interestEarned = 0.0;
	finalInterest = 0.0;

	for (i = 1; i <= numYears; ++i) {

		for (j = 1; j <= 12; ++j) {
			interestEarned = (initialInvestment + monthlyDeposit) * interestRate;
			balance = initialInvestment + monthlyDeposit + interestEarned;
			finalInterest += interestEarned;
			initialInvestment = balance;
		}

		cout << " " << i << "\t\t" << "$";
		cout << fixed << setprecision(2) << balance;
		cout << "\t\t" << "$" << finalInterest << endl;
		cout << endl;

		finalInterest = 0.0;
	}
}