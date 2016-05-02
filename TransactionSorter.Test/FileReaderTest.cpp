#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FileReader\FileReader.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileReaderTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CanBeCreated)
		{
			CFileReader reader;
		}

		TEST_METHOD(OpenFile)
		{
			CFileReader reader;
			reader.Read("C:\Users\Shane\Downloads\AmexTransactionsApr14-30.csv");
		}

		TEST_METHOD(GetRows)
		{
			CFileReader reader;
			reader.Read("C:\Users\Shane\Downloads\AmexTransactionsApr14-30.csv");
			auto rows = reader.GetRows();
		}
	};
}