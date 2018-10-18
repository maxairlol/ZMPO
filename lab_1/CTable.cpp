#include "pch.h"
#include "CTable.h"

using namespace std;

CTable::CTable()
{
	s_name = S_DEFAULT;
	i_tab_size = I_DEFAULT_TAB_SIZE;
	pi_tab = new int[i_tab_size];
	cout << "bezp.:" << s_name << endl;
}//CTable::CTable()

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	i_tab_size = iTableLen;
	pi_tab = new int[i_tab_size];
	cout << "parametr:" << s_name << endl;
}//CTable::CTable(string sName, int iTableLen)

CTable::CTable(const CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	i_tab_size = pcOther.i_tab_size;
	pi_tab = new int[i_tab_size];
	for (int i = 0; i < i_tab_size; i++)
	{
		pi_tab[i] = pcOther.pi_tab[i];
	}
	cout << "kopiuj:" << s_name << endl;
}//CTable::CTable(const CTable &pcOther)

CTable::CTable(const CTable &pcOther, int iExtend)
{
	s_name = pcOther.s_name + "_extend";
	i_tab_size = pcOther.i_tab_size * iExtend;
	pi_tab = new int[i_tab_size];
	for (int i = 0; i < i_tab_size; i++)
	{
		pi_tab[i] = pcOther.pi_tab[i];
	}
	cout << "wydluz:" << s_name << endl;
}//CTable::CTable(const CTable &pcOther, int iExtend)

CTable::~CTable()
{
	delete[] pi_tab;
	cout << "usuwam:" << s_name << endl;
}//CTable::~CTable()

void CTable::vSetName(string sName)
{
	s_name = sName;
}//void CTable::vSetName(string sName)

string CTable::changeTabLength(int iNewS)
{
	string s_result = S_SUCCESS;
	if (iNewS < 1)
	{
		s_result = S_FAIL;
	}
	else
	{
		int* pi_new_tab = new int[iNewS];
		for (int i = 0; (i < i_tab_size) && (i < iNewS); i++)
		{
			pi_new_tab[i] = pi_tab[i];
		}
		delete[] pi_tab;
		i_tab_size = iNewS;
		pi_tab = pi_new_tab;
	}
	
	return s_result;
}//string CTable::changeTabLength(int iNewS)

string CTable::iSetElement(int iPos, int iVal)
{
	string s_result = S_SUCCESS;
	if ((iPos < 0) || (iPos > i_tab_size - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		pi_tab[iPos] = iVal;
	}
	return s_result;
}//string CTable::iSetElement(int iPos, int iVal)

string CTable::iGetElement(int iPos, int &piValue)
{
	string s_result = S_SUCCESS;
	if ((iPos < 0) || (iPos > i_tab_size - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		piValue = pi_tab[iPos];
	}
	return s_result;
}//string CTable::iGetElement(int iPos)

string CTable::sGetInfo()
{
	string s_result = s_name + " len:" + to_string(i_tab_size) + " values:";
	int i = 0;
	for (; i < i_tab_size - 1; i++)
	{
		s_result += to_string(pi_tab[i]) + ",";
	}
	s_result += to_string(pi_tab[i]);
	return s_result;
}//string CTable::sGetInfo()
