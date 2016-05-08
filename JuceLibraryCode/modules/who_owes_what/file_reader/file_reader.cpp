#include "file_reader.h"
#include <fstream>
#include <sstream>
#include "..\transaction_sorter\transaction_sorter.h"


CFileReader::CFileReader(CTransactionSorter* sorter)
{
	_sorter = sorter;
}

void CFileReader::Process(const std::string& filePath)
{
	// Open File (omit error checking for now)
	std::ifstream file(filePath);
	std::string line;

	// Each line in the file is a new transaction
	while (std::getline(file, line))
	{
		auto date = GetColumn(DATE, line);
		auto amount = GetColumn(AMOUNT, line);
		auto description = GetColumn(DESCRIPTION, line);

		_sorter->AddTransaction(std::stod(amount), date, description);
	}
}

// TODO: Hacky method. Very inefficient. Refactor.
std::string CFileReader::GetColumn(expectedColumns column, const std::string& line) const
{
	std::stringstream lineStream(line);
	std::string result;

	// Use getline to split the line at each comma.
	int i = 0;
	while (i <= column)
	{
		std::getline(lineStream, result, ',');
		++i;
	}

	TrimQuotations(result);
	return result;
}

void CFileReader::TrimQuotations(std::string& s) const
{
	std::string getRidOf = "\"";
	std::string replaceWith = "";

	// Inspired by http://stackoverflow.com/a/14678964/1704355
	size_t pos = 0;
	while ((pos = s.find(getRidOf, pos)) != std::string::npos)
	{
		s.replace(pos, getRidOf.length(), replaceWith);
		pos += replaceWith.length();
	}
}