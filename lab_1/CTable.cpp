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
	pi_tab = new int[pcOther.i_tab_size];
	i_tab_size = pcOther.i_tab_size;
	for (int i = 0; i < pcOther.i_tab_size; i++)
	{
		pi_tab[i] = pcOther.pi_tab[i];
	}
	cout << "kopiuj:" << s_name << endl;
}//CTable::CTable(const CTable &pcOther)

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
	string s_result;
	if (iNewS < 1)
	{
		s_result = S_FAIL;
	}
	else
	{
		i_tab_size = iNewS;
		int* pi_new_tab = new int[i_tab_size];
		for (int i = 0; (i < i_tab_size) && (i < iNewS); i++)
		{
			pi_new_tab[i] = pi_tab[i];
		}
		delete[] pi_tab;
		pi_tab = pi_new_tab;
		s_result = S_SUCCESS;
	}
	

	return s_result;
}//string CTable::changeTabLength(int iNewS)

string CTable::iSetElement(int iPos, int iVal)
{
	string s_result;
	if ((iPos < 0) || (iPos > i_tab_size - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		pi_tab[iPos] = iVal;
		s_result = S_SUCCESS;
	}
	return s_result;
}//string CTable::iSetElement(int iPos, int iVal)

string CTable::iGetElement(int iPos)
{
	string s_result;
	if ((iPos < 0) || (iPos > i_tab_size - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		s_result = S_SUCCESS;
		cout << pi_tab[iPos] << endl;
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

bool isParamFine(string sParam)
{
	bool b_result = true;
	if (sParam == "" || (sParam[0] == '0' && sParam.size() > 1)) b_result = false;
	for (int i = 0; i < sParam.length() && b_result; i++)
		if (!(sParam[i] >= '0' && sParam[i] <= '9' || sParam[i] == ' '))
		{
			b_result = false;
		}
	return b_result;
}//bool isParamFine(string sParam)

int countSpaces(string sStream)
{
	int i_count = 0;
	for (int i = 0; i < sStream.length(); i++)
	{
		if (isspace(sStream.at(i)))
		{
			i_count++;
		}
	}
	return i_count;
}//int countSpaces(string sStream)

string createCTableVec(vector<CTable*> &vCTable, int iSize)
{
	if (!vCTable.empty())
	{
		for (auto it = vCTable.begin(); it != vCTable.end(); ++it) {
			delete *it;
		}
		vCTable.clear();
	}
	
	for (int i = 0; i < iSize; i++)
	{
		vCTable.push_back(new CTable("default" + to_string(i), 10));
	}
	return S_SUCCESS;
}//void createCTableVec(vector<CTable*> &vCTable, int iSize)

string changeCTableTabSize(vector<CTable*> &vCTable, int iPos, int iSize)
{
	string s_result = S_SUCCESS;
	if ((vCTable.empty()) || (iPos < 0) || (iPos > (vCTable.size() - 1)))
	{
		s_result = S_FAIL;
	}
	else
	{
		vCTable.at(iPos)->changeTabLength(iSize);
	}
	return s_result;
}//string changeCTableTabSize(vector<CTable*> &vCTable, int iPos, int iSize)

string deleteCTableVecElement(vector<CTable*> &vCTable, int iPos)
{
	string s_result = S_SUCCESS;
	if ((vCTable.empty()) || (iPos < 0) || (iPos > vCTable.size() - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		delete vCTable.at(iPos);
		vCTable.erase(vCTable.begin() + iPos);
	}
	return s_result;
}//string deleteCTableVecElement(vector<CTable*> &vCTable, int iPos)

string deleteAllCTableVecElements(vector<CTable*> &vCTable)
{
	string s_result = S_FAIL;
	if (!vCTable.empty())
	{
		for (auto it = vCTable.begin(); it != vCTable.end(); ++it) {
			delete *it;
		}
		vCTable.clear();
		s_result = S_SUCCESS;
	}
	return s_result;
}//void deleteAllCTableVecElements(vector<CTable*> &vCTable)

string changeCTableName(vector<CTable*> &vCTable, int iPos, string sNewName)
{
	string s_result;
	if (vCTable.empty() || iPos < 0 || iPos > (vCTable.size() - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		s_result = S_SUCCESS;
		vCTable.at(iPos)->vSetName(sNewName);
	}
	return s_result;
}//string changeCTableName(vector<CTable*> &vCTable, int iPos, string sNewName)

string printCTable(vector<CTable*> &vCTable, int iPos)
{
	string s_result;
	if (vCTable.empty() || iPos < 0 || iPos >(vCTable.size() - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		s_result = vCTable.at(iPos)->sGetInfo() + "\n" + S_SUCCESS;
	}
	return s_result;
}//string printCTable(vector<CTable*> &vCTable, int iPos)

string insertToCTable(vector<CTable*> &cTabVec, int iCTablePos, int iPos, int iVal)
{
	string s_result = S_SUCCESS;
	if (cTabVec.empty() || iCTablePos < 0 || iCTablePos >(cTabVec.size() - 1) || iPos < 0 || iPos > (cTabVec.at(iCTablePos)->iGetTabSize() - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		cTabVec.at(iCTablePos)->iSetElement(iPos,iVal);
	}
	return s_result;
}//string insertToCTable(vector<CTable*> &vCTable, int iCTablePos, int iPos, int iVal)

string copyCTable(vector<CTable*> &vCTable, int iPos)
{
	string s_result = S_SUCCESS;
	if (vCTable.empty() || iPos < 0 || iPos >(vCTable.size() - 1))
	{
		s_result = S_FAIL;
	}
	else
	{
		CTable* copyCTable = new CTable(*vCTable.at(iPos));
		vCTable.push_back(copyCTable);
	}
	return s_result;
}//string copyCTab(vector<CTable*> &cTabVec, int iPos)


int main()
{
	string tempParse;
	cout << "mvec [size] -- Create a vector of CTable" << endl;
	cout << "chts [index] [newSize] -- Change tab size of CTable" << endl;
	cout << "chtn [index] [newName] -- Change CTable name on index position" << endl;
	cout << "itt [index] [position] [value]-- Insert value into CTable on index" << endl;
	cout << "cct [index] -- Create a copy of CTable and add to vector"  << endl;
	cout << "del [index]  -- Delete a CTable element on index position" << endl;
	cout << "delall -- Delete all CTable vector elements" << endl;
	cout << "print [index] -- Print CTable" << endl;
	cout << "STOP -- Close the program" << endl;


	vector<CTable*> v_CTable;

	while (1) {
		getline(cin, tempParse);
		// parser
		stringstream ss(tempParse);
		string param0, param1, param2,param3;
		getline(ss, param0, ' ');
		//mvec
		if (param0 == "mvec") {
			getline(ss, param1, ' ');
			if (isParamFine(param1) && countSpaces(ss.str()) < 2) {
				cout << createCTableVec(v_CTable, stoi(param1)) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "chts") {
			getline(ss, param1, ' ');
			getline(ss, param2, ' ');
			if (isParamFine(param1) && isParamFine(param2) && countSpaces(ss.str()) < 3) {
				cout << changeCTableTabSize(v_CTable, stoi(param1), stoi(param2)) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "chtn") {
			getline(ss, param1, ' ');
			getline(ss, param2, ' ');
			if (isParamFine(param1) && countSpaces(ss.str()) < 3) {
				cout << changeCTableName(v_CTable, stoi(param1), param2) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "itt") {
			getline(ss, param1, ' ');
			getline(ss, param2, ' ');
			getline(ss, param3, ' ');
			if (isParamFine(param1) && isParamFine(param2) && isParamFine(param3) && countSpaces(ss.str()) < 4) {
				cout << insertToCTable(v_CTable, stoi(param1), stoi(param2), stoi(param3)) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "cct") {
			getline(ss, param1, ' ');
			if (isParamFine(param1) && countSpaces(ss.str()) < 2) {
				cout << copyCTable(v_CTable, stoi(param1)) << endl;;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "print") {
			getline(ss, param1, ' ');
			if (isParamFine(param1) && countSpaces(ss.str()) < 2)
			{
				cout << printCTable(v_CTable, stoi(param1)) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "del") {
			getline(ss, param1, ' ');
			if (isParamFine(param1) && countSpaces(ss.str()) < 2) {
				cout << deleteCTableVecElement(v_CTable,stoi(param1)) << endl;
			}
			else { cout << S_INVALID_P << endl; }
		}
		else if (param0 == "delall" && countSpaces(ss.str()) < 1) {
		   cout << deleteAllCTableVecElements(v_CTable) << endl;
		}
		else if (param0 == "STOP" && countSpaces(ss.str()) < 1) {
			cout << deleteAllCTableVecElements(v_CTable) << endl;
			return 0;
		}
		else {
			cout << S_UNKNOWN_C << endl;
		}
		// parser end
	}
	return 0;
}
