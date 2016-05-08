
#include "../JuceLibraryCode/JuceHeader.h"

class TransactionSorterTest : public UnitTest
{
public:
	TransactionSorterTest() : UnitTest("TransactionSorter testing") {}
	void runTest() override
	{
		beginTest("TransactionSorterCanBeCreated");
		{
			CTransactionSorter sorter;
		}

		beginTest("AddTransaction");
		{
			CTransactionSorter sorter;
			sorter.AddTransaction(3.33);
		}

		beginTest("GetTotal");
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			sorter.AddTransaction(amount);
			expectEquals(amount, sorter.GetTotal());
		}

		beginTest("GetTotalTwoTransactions");
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			sorter.AddTransaction(amount);
			sorter.AddTransaction(amount);
			expectEquals(amount * 2, sorter.GetTotal());
		}

		beginTest("TransactionReturned");
		{
			CTransactionSorter sorter;
			auto transaction = sorter.AddTransaction(3.33);
		}

		beginTest("TransactionHasAmount");
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			auto transaction = sorter.AddTransaction(amount);
			expectEquals(amount, transaction->GetAmount());
		}

		beginTest("TransactionHasNegativeAmount");
		{
			CTransactionSorter sorter;
			const double amount = -213.73;

			auto transaction = sorter.AddTransaction(amount);
			expectEquals(amount, transaction->GetAmount());
		}

		beginTest("TransactionHasGroup");
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			auto transaction = sorter.AddTransaction(amount);
			transaction->GetGroup();
		}

		beginTest("TransactionGroupDefaultsToUnsorted");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string unsorted = "Unsorted";
			expectEquals(unsorted, transaction->GetGroup());
		}

		beginTest("TransactionSetGroupWorks");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);
			expectEquals(group, transaction->GetGroup());
		}

		beginTest("GetTotalByGroup");
		{
			CTransactionSorter sorter;

			const std::string group = "Shane";
			sorter.GetTotal(group);
		}

		beginTest("GetTotalByGroupDefault");
		{
			CTransactionSorter sorter;

			const std::string group = "Shane";
			const double total = 0;
			expectEquals(total, sorter.GetTotal(group));
		}

		beginTest("GetTotalByGroupWithTransaction");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);

			expectEquals(amount, sorter.GetTotal(group));
		}

		beginTest("GetTotalByGroupWithNoTransaction");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);

			const std::string otherGroup = "this group has no transactions";
			const double otherGroupAmount = 0;
			expectEquals(otherGroupAmount, sorter.GetTotal(otherGroup));
		}

		beginTest("GetNextUnsortedTransactionNullIfNone");
		{
			CTransactionSorter sorter;
			expect(sorter.GetNextUnsortedTransaction().get() == nullptr);
		}

		beginTest("GetNextUnsortedTransactionValid");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			expect(transaction == sorter.GetNextUnsortedTransaction());
		}

		beginTest("AddTransactionWithDateAndDescription");
		{
			CTransactionSorter sorter;

			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";
			sorter.AddTransaction(amount, date, description);
		}

		beginTest("TransactionHasDateAndDescription");
		{
			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";

			CTransaction transaction(amount, date, description);
		}

		beginTest("TransactionGetDate");
		{
			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";

			CTransaction transaction(amount, date, description);

			expectEquals(date, transaction.GetDate());
		}

		beginTest("TransactionGetDescription");
		{
			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";

			CTransaction transaction(amount, date, description);

			expectEquals(description, transaction.GetDescription());
		}

		beginTest("AddTransactionGetDateAndDescription");
		{
			CTransactionSorter sorter;

			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";
			sorter.AddTransaction(amount, date, description);

			auto transaction = sorter.GetNextUnsortedTransaction();

			expectEquals(date, transaction->GetDate());
			expectEquals(description, transaction->GetDescription());
		}

		beginTest("GetGroupCountNoTransactions");
		{
			CTransactionSorter sorter;
			expectEquals(0, sorter.getTransactionCount());
		}

		beginTest("GetGroupCount");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);

			expectEquals(1, sorter.getTransactionCount("Shane"));
		}

		beginTest("GetGroupCountNoGroupSpecified");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			sorter.AddTransaction(amount);

			expectEquals(1, sorter.getTransactionCount());

			sorter.AddTransaction(amount);
			expectEquals(2, sorter.getTransactionCount());
		}

		beginTest("GetUnsortedTransactionCount");
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			expectEquals(1, sorter.getUnsortedTransactionCount());

			const std::string group = "Shane";
			transaction->SetGroup(group);

			expectEquals(0, sorter.getUnsortedTransactionCount());
		}
	}
};
// Creating a static instance will automatically add the instance to the array
// returned by UnitTest::getAllTests(), so the test will be included when you call
// UnitTestRunner::runAllTests()
static TransactionSorterTest test;