// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FILEREADER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FILEREADER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FILEREADER_EXPORTS
#define FILEREADER_API __declspec(dllexport)
#else
#define FILEREADER_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

class CTransactionSorter;

// This class is exported from the FileReader.dll
class FILEREADER_API CFileReader {
public:
	CFileReader(CTransactionSorter* sorter);

	void Process(const std::string& filePath);

private:
	enum expectedColumns
	{
		DATE,
		REFERENCE,
		AMOUNT,
		DESCRIPTION,
		PROCESS_DATE
	};

	std::string GetColumn(expectedColumns column, const std::string& line) const;
	void TrimQuotations(std::string& s) const;

	CTransactionSorter* _sorter;
};
