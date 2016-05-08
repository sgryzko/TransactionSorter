#ifndef TRANSACTION_SORTER_H_INCLUDED
#define TRANSACTION_SORTER_H_INCLUDED


#include <string>
#include <vector>
#include <memory>

const std::string unsortedGroup = "Unsorted";

// TODO: Move CTransaction class into a separate file.

class CTransaction 
{
public:
	CTransaction(double amount, const std::string& date,
		const std::string& description);

	double GetAmount() const;
	const std::string& GetDate() const;
	const std::string& GetDescription() const;
	const std::string& GetGroup() const;

	// TODO: Disable copy constructor and assignment operator so that the only way to create Transactions is through the sorter?

	void SetGroup(const std::string& group);

private:
	double _amount;
	std::string _date;
	std::string _description;
	std::string _group;
};

class CTransactionSorter 
{
public:
	CTransactionSorter(void);

	std::shared_ptr<CTransaction> AddTransaction(const double amount,
		const std::string& date = "", const std::string& description = "");
	double GetTotal(const std::string& group = unsortedGroup) const;
	std::shared_ptr<CTransaction> GetNextUnsortedTransaction();

	int getTransactionCount(const std::string& group = "") const;
	int CTransactionSorter::getUnsortedTransactionCount() const;

private:
	std::vector<std::shared_ptr<CTransaction>> _transactions;
};

#endif // TRANSACTION_SORTER_H_INCLUDED