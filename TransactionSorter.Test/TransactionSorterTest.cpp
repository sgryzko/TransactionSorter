#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TransactionSorter\TransactionSorter.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString<std::shared_ptr<CTransaction>>(const std::shared_ptr<CTransaction>& transaction)
			{
				return std::to_wstring(transaction->GetAmount());
			}
		}
	}
}

namespace TransactionSorterTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TransactionSorterCanBeCreated)
		{
			CTransactionSorter sorter;
		}

		TEST_METHOD(AddTransaction)
		{
			CTransactionSorter sorter;
			sorter.AddTransaction(3.33);
		}

		TEST_METHOD(GetTotal)
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			sorter.AddTransaction(amount);
			Assert::AreEqual(amount, sorter.GetTotal());
		}

		TEST_METHOD(GetTotalTwoTransactions)
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			sorter.AddTransaction(amount);
			sorter.AddTransaction(amount);
			Assert::AreEqual(amount * 2, sorter.GetTotal());
		}

		TEST_METHOD(TransactionReturned)
		{
			CTransactionSorter sorter;
			auto transaction = sorter.AddTransaction(3.33);
		}

		TEST_METHOD(TransactionHasAmount)
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			auto transaction = sorter.AddTransaction(amount);
			Assert::AreEqual(amount, transaction->GetAmount());
		}

		TEST_METHOD(TransactionHasNegativeAmount)
		{
			CTransactionSorter sorter;
			const double amount = -213.73;

			auto transaction = sorter.AddTransaction(amount);
			Assert::AreEqual(amount, transaction->GetAmount());
		}

		TEST_METHOD(TransactionHasGroup)
		{
			CTransactionSorter sorter;
			const double amount = 3.33;

			auto transaction = sorter.AddTransaction(amount);
			transaction->GetGroup();
		}

		TEST_METHOD(TransactionGroupDefaultsToUnsorted)
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string defaultGroup = "Unsorted";
			Assert::AreEqual(defaultGroup, transaction->GetGroup());
		}

		TEST_METHOD(TransactionSetGroupWorks)
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);
			
			const std::string group = "Shane";
			transaction->SetGroup(group);
			Assert::AreEqual(group, transaction->GetGroup());
		}

		TEST_METHOD(GetTotalByGroup)
		{
			CTransactionSorter sorter;

			const std::string group = "Shane";
			sorter.GetTotal(group);
		}

		TEST_METHOD(GetTotalByGroupDefault)
		{
			CTransactionSorter sorter;

			const std::string group = "Shane";
			const double total = 0;
			Assert::AreEqual(total, sorter.GetTotal(group));
		}

		TEST_METHOD(GetTotalByGroupWithTransaction)
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);

			Assert::AreEqual(amount, sorter.GetTotal(group));
		}

		TEST_METHOD(GetTotalByGroupWithNoTransaction)
		{
			CTransactionSorter sorter;

			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			const std::string group = "Shane";
			transaction->SetGroup(group);

			const std::string otherGroup = "this group has no transactions";
			const double otherGroupAmount = 0;
			Assert::AreEqual(otherGroupAmount, sorter.GetTotal(otherGroup));
		}

		TEST_METHOD(GetNextUnsortedTransactionNullIfNone)
		{
			CTransactionSorter sorter;
			Assert::IsNull(sorter.GetNextUnsortedTransaction().get());
		}

		TEST_METHOD(GetNextUnsortedTransactionValid)
		{
			CTransactionSorter sorter;
			
			const double amount = 3.33;
			auto transaction = sorter.AddTransaction(amount);

			Assert::AreEqual(transaction, sorter.GetNextUnsortedTransaction());
		}

		TEST_METHOD(AddTransactionWithDateAndDescription)
		{
			CTransactionSorter sorter;

			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";
			auto transaction = sorter.AddTransaction(amount, date, description);
		}

		TEST_METHOD(TransactionHasDateAndDescription)
		{
			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";

			CTransaction transaction(amount, date, description);
		}

		TEST_METHOD(TransactionGetDate)
		{
			const double amount = 1999.00;
			const std::string date = "2016-05-02";
			const std::string description = "ROLI Seabord GRAND";

			CTransaction transaction(amount, date, description);

			Assert::AreEqual(date, transaction.GetDate());
		}
	};
}