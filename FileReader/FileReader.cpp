// FileReader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "FileReader.h"


// This is an example of an exported variable
FILEREADER_API int nFileReader=0;

// This is an example of an exported function.
FILEREADER_API int fnFileReader(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see FileReader.h for the class definition
CFileReader::CFileReader()
{
    return;
}

void CFileReader::Read(std::string filePath)
{
}

std::vector<std::vector<std::string>> CFileReader::GetRows() const
{
	return std::vector<std::vector<std::string>>();
}