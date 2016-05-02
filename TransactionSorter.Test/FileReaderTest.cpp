#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FileReader\FileReader.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileReaderTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(FileReaderCanBeCreated)
		{
			CFileReader reader;
		}
	};
}