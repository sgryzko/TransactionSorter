#include "stdafx.h"
#define DONT_SET_USING_JUCE_NAMESPACE 1
#include "../JuceLibraryCode/JuceHeader.h"

#include "CppUnitTest.h"


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

			double tolerance = 0.0001;
			Assert::AreEqual(855.96, sorter.GetTotal(), tolerance);
		}
	};
}