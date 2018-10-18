#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define S_DEFAULT "DEFAULT_NAME";
#define I_DEFAULT_TAB_SIZE 10;
#define S_SUCCESS "SUCCESS"
#define S_FAIL "FAIL"
#define S_UNKNOWN_C "UNKNOWN_COMAND!"
#define S_INVALID_P "INVALID_PARAMETERS!"

class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
	CTable(const CTable &pcOther, int iExtend);
	~CTable();

	void vSetName(string sName);
	string changeTabLength(int iNewS);
	string iSetElement(int iPos, int iElement);
	string iGetElement(int iPos, int &piValue);
	string sGetInfo();
	int iGetTabSize() { return i_tab_size; };

private:
	string s_name;
	int* pi_tab;
	int i_tab_size;
};

