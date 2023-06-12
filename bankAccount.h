#pragma once

class bankAccount {
private:
	double balance{};
	double deposit{};
	double interest{};
	double rate{};
	int transactions{};

public:
	bankAccount(double r = 0.045, double bal = 0.0) {
		balance = bal;
		rate = r;
		interest = 0;
		transactions = 0;
	}

	void makeDeposit(double ammount) {
		balance += ammount;
		transactions++;
	}

	bool withdraw(double ammount);

	void calcIntrest() {
		interest = balance * rate;
		balance += interest;
	}

	double getBalance() {
		return balance;
	}

	double getInterest() {
		return interest;
	}

	int getTransactions() {
		return transactions;
	}
};
