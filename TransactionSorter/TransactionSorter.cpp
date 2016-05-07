// TransactionSorter.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TransactionSorter.h"

// This is the constructor of a class that has been exported.
// see TransactionSorter.h for the class definition
CTransactionSorter::CTransactionSorter()
{
}

std::shared_ptr<CTransaction> CTransactionSorter::AddTransaction(const double amount,
	const std::string& date, const std::string& description)
{
	auto transaction = std::make_shared<CTransaction>(amount, date, description);
	_transactions.push_back(transaction);

	return transaction;
}

double CTransactionSorter::GetTotal(const std::string& group) const
{
	double total = 0;

	for each (auto transaction in _transactions)
	{
		if (transaction->GetGroup() == group)
		{
			total += transaction->GetAmount();
		}
	}

	return total;
}

std::shared_ptr<CTransaction> CTransactionSorter::GetNextUnsortedTransaction()
{
	for each (auto transaction in _transactions)
	{
		if (transaction->GetGroup() == unsortedGroup)
		{
			return transaction;
		}
	}

	return std::shared_ptr<CTransaction>();
}

CTransaction::CTransaction(double amount, const std::string& date, const std::string& description)
{
	_amount = amount;
	_date = date;
	_description = description;
	_group = unsortedGroup;
}

double CTransaction::GetAmount() const
{
	return _amount;
}

const std::string& CTransaction::GetDate() const
{
	return _date;
}

const std::string& CTransaction::GetDescription() const
{
	return _description;
}

const std::string& CTransaction::GetGroup() const
{
	return _group;
}

void CTransaction::SetGroup(const std::string& group)
{
	_group = group;
}

int CTransactionSorter::getTransactionCount(const std::string & group) const
{
	int count = 0;

	for each (auto transaction in _transactions)
	{
		if (group == "" || transaction->GetGroup() == group)
		{
			++count;
		}
	}

	return count;
}

int CTransactionSorter::getUnsortedTransactionCount() const
{
	return getTransactionCount(unsortedGroup);
}