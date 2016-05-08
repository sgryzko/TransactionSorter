
#include "../JuceLibraryCode/JuceHeader.h"

class FileReaderTest : public UnitTest
{
public:
	FileReaderTest() : UnitTest("FileReader testing") {}
	void runTest() override
	{
		beginTest("CanBeCreated");
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);
		}

		beginTest("ProcessFile");
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);

			reader.Process("../../../ExampleTransactionFile.csv");
		}

		beginTest("ProcessFileSum");
		{
			CTransactionSorter sorter;
			CFileReader reader(&sorter);
			reader.Process("../../../ExampleTransactionFile.csv");

			double expectedSum = 855.96;
			double difference = abs(sorter.GetTotal() - expectedSum);
			double tolerance = 0.0001;
			expect(difference < tolerance);
		}
	}
};
// Creating a static instance will automatically add the instance to the array
// returned by UnitTest::getAllTests(), so the test will be included when you call
// UnitTestRunner::runAllTests()
static FileReaderTest test;