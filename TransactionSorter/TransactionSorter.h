// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TRANSACTIONSORTER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TRANSACTIONSORTER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TRANSACTIONSORTER_EXPORTS
#define TRANSACTIONSORTER_API __declspec(dllexport)
#else
#define TRANSACTIONSORTER_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <memory>

const std::string unsortedGroup = "Unsorted";

// TODO: Move CTransaction class into a separate file.

// This class is exported from the TransactionSorter.dll
class TRANSACTIONSORTER_API CTransaction {
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

// This class is exported from the TransactionSorter.dll
class TRANSACTIONSORTER_API CTransactionSorter {
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
