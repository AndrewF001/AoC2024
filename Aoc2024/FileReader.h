#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class FileReader
{
public:
	FileReader(std::string);
	std::string ReadStraight();
	std::vector<std::string> ReadLine();
	std::vector<int> ReadInts();
	std::vector<int> ReadInts(std::vector<std::string>);
	std::vector<long long>ReadLong();
	std::vector<std::vector<char>> ReadCharGrid();
	std::vector<std::string> SplitString(char);
	static std::vector<std::string> SplitString(std::string, char);
	std::vector<int> SplitToInt(std::string, char);
	void PrintFiles();
	void ReplaceChar(std::string* str, char Look, char Replace);

private:
	bool OpenFile();
	void CloseFile();
	std::ifstream Reader;
	std::string FileName;


};



