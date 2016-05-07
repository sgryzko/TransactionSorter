// CommandLineInterface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\FileReader\FileReader.h"
#include "..\TransactionSorter\TransactionSorter.h"
#include <iostream>


void OutputTotal(const std::string& category, CTransactionSorter* sorter)
{
	std::printf("%-8s   ", category.c_str());
	std::printf("%8.2f", sorter->GetTotal(category));
	std::cout << "\n";
}

int main()
{
	std::cout << "Welcome to The Transaction Sorter.\n\n";
	std::cout << "Please specify the full path of a valid CSV transaction file.\n";

	std::string transactionFile;
	std::getline(std::cin, transactionFile);

	CTransactionSorter sorter;
	CFileReader reader(&sorter);

	// TODO: Wrap this call and re-prompt if it doesn't work properly.
	reader.Process(transactionFile);

	const std::string directions = "please enter C for Carolyn, S for Shane, or J for Joint.\n";

	std::cout << "\nThanks!\nFor each transaction, " << directions << "\n";
	std::cout << "When you're done, I'll tell you who owes what.\n\n";
	std::cout << "Date         Amount Description                              Category\n";
	std::cout << "---------------------------------------------------------------------";

	std::shared_ptr<CTransaction> currentTransaction = nullptr;

	while ((currentTransaction = sorter.GetNextUnsortedTransaction()) != nullptr)
	{
		std::cout << std::endl << currentTransaction->GetDate();
		std::printf(" %*.2f", 8, currentTransaction->GetAmount());
		std::printf(" %-40.40s ", currentTransaction->GetDescription().c_str());

		char category;
		std::cin >> category;

		switch (category)
		{
		case 'C':
		case 'c':
			currentTransaction->SetGroup("Carolyn");
			break;
		case 'S':
		case 's':
			currentTransaction->SetGroup("Shane");
			break;
		case 'J':
		case 'j':
			currentTransaction->SetGroup("Joint");
			break;
		default:
			std::cout << "Sorry, I didn't recognize '" << category << "'. " << directions;
			break;
		}
	}

	std::cout << "\n\nCategory      Total\n-------------------\n";
	OutputTotal("Carolyn", &sorter);
	OutputTotal("Shane", &sorter);
	OutputTotal("Joint", &sorter);

	std::cout << "\nBe sure to write these down so you don't forget them!\n";

	// Windows only. See http://stackoverflow.com/a/2529636/1704355.
	system("pause");

    return 0;
}