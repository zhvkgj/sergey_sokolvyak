#ifndef __handling_file_h__
#define __handling_file_h__
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

std::vector <std::string> myFiles;

void assignFile(std::string fileName)
{
	std::ifstream fin(fileName.c_str(), std::ios::trunc);
	if (!fin.is_open()) std::cerr << "File cant be created!\n";
	else myFiles.push_back(fileName);
}

void deleteFile(std::string fileName)
{
	if (remove(fileName.c_str())) std::cerr << "Error!\n";
	else std::cout << fileName << " was deleted!\n";
}

void pushBackString(std::string fileName, std::string myStr)
{
	std::ofstream fout(fileName.c_str(), std::ios::ate);
	if (!fout.is_open()) std::cerr << "File cant be opened!\n";
	else fout <<"\n"<<myStr;
}

void popBackString(std::string fileName)
{
	std::ifstream fin(fileName.c_str(), std::ios::ate);
	if (!fin.is_open()) std::cerr << "File cant be opened!\n";
	else 

}

void printFile(std::string fileName)
{
	std::string tempStr;
	std::ifstream fin(fileName.c_str());
	if (!fin.is_open()) std::cerr << "File cant be opened!\n";
	else 
		while (getline(fin, tempStr)) 
			std::cout << tempStr << '\n';
}


#endif __handling_file_h__
