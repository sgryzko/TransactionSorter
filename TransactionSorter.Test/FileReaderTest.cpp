#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FileReader\FileReader.h"
#include "..\TransactionSorter\TransactionSorter.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileReaderTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CanBeCreated)
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);
		}

		TEST_METHOD(ProcessFile)
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);
			reader.Process("ExampleTransactionFile.csv");
		}

		TEST_METHOD(ProcessFileSum)
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);
			reader.Process("ExampleTransactionFile.csv");

			Assert::AreEqual(-2293.45, sorter.GetTotal());
		}
	};
}