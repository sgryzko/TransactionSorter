
#ifndef FILE_READER_H_INCLUDED
#define FILE_READER_H_INCLUDED

// TODO: Is it bad to have includes in headers? If so should I forward declare string? Switch to Juce::String?
#include <string>

class CTransactionSorter;

class CFileReader 
{
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

#endif   // FILE_READER_H_INCLUDED