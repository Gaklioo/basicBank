/*
Deposit Money,
Withdraw Money
Get balance
Get Interest
Get transaction ammount +1 per transaction
Calculate Interest
*/

#include <iostream>
#include <Windows.h>
#include "class.h"

bool bankAccount::withdraw(double ammount) {
	if (balance < ammount) {
		return false;
	}
	else {
		balance -= ammount;
		transactions++;
		return true;
	}
}

double getAccountBalance(bankAccount &a) {
	return a.getBalance();
}

void makeAccountDeposit(bankAccount& a, double deposit) {
	a.makeDeposit(deposit);
}

double getAccountInterest(bankAccount& a) {
	return a.getInterest();
}

int getAccountTransactions(bankAccount& a) {
	return a.getTransactions();
}

void calcInterest(bankAccount& a) {
	std::cout << "Interest added to current bank balance." << std::endl;
	std::cout << "Current Balance: " << a.getBalance();
	std::cout << "Balance after interest.";
	a.calcIntrest();
	std::cout << a.getBalance() << std::endl;
}

//Start stuff
void doBank(bankAccount& account) {
	int response{};
	int depositAmmount{};
	int withdrawAmmount{};
	std::cout << std::endl;
	std::cout << "-----  Welcome to Gak Bank -----" << std::endl;
	std::cout << "----- Please choose a option-----";
	std::cout << "\n[1] Get Account Balance";
	std::cout << "\n[2] Deposit Money into Account";
	std::cout << "\n[3] Withdraw Money From Account";
	std::cout << "\n[4] Get Interest Rate";
	std::cout << "\n[5] Transaction Ammount";
	std::cout << "\n[6] Calculate Interest" << std::endl;
	std::cin >> response;

	switch (response)
	{
	case 1:
		std::cout << getAccountBalance(account);
		break;
	case 2:
		std::cout << "Enter an ammount to deposit: ";
		std::cin >> depositAmmount;
		makeAccountDeposit(account, depositAmmount);
		break;
	case 3:
		Sleep(2000);
		system("CLS");
		std::cout << "Please enter the ammount to withdraw: ";
		std::cin >> withdrawAmmount;

		if (account.withdraw(withdrawAmmount)) {
			std::cout << withdrawAmmount << " Has been withdrawn" << std::endl;
			std::cout << "Current Account Balance: " << account.getBalance();
		}
		else {
			std::cout << "You do not have enough to withdraw." << std::endl;
			Sleep(2000);
			std::cin.clear();
			system("CLS");
			doBank(account);
		}
		break;
	case 4:
		std::cout << getAccountInterest(account) << std::endl;
		break;
	case 5:
		std::cout << getAccountTransactions(account) << std::endl;
		break;
	case 6:
		calcInterest(account);
		break;
	default:
		std::cout << "Please enter a valid choice.";
		Sleep(2000);
		system("CLS");
		std::cin.clear();
		doBank(account);
		break;
	}
	doBank(account);
}

int main() {
	bankAccount account;
	doBank(account);
}