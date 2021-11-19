#include "includes.h"
#include "TableFactory.h"
#include "table.h"
#include "DataColumn.h"

using namespace std; 

Table::Table()
{
  //switch():
  //  case
}

void Table::PushData()
{

	return; 
}

Table::Table(vector<vector<string>> fData)
{
	this->fileData = fData; 

}

vector<vector<string>> Table::GetFileData()
{
	return this->fileData; 
}

Table::Table(/*vector<vector<string>> fData*/)
{

	TableFactory temp;
	Table t; 
	DataColumn tcol; 
	vector <string> stemp; 
	int pos = 0;
	int pos2 = 0; 

	for (int i = 0; i < temp.GetSchemaData.size(); i++)
	{
		string str = temp.GetSchemaData().at(i).at(0);
		
		stemp = temp.FindSchema(str);
		for (int j = 0; j < stemp.size(); j++)
		{
			string s = stemp.at(j);
			if (s.find("int") || s.find("str"))
			{
				pos = s.find_last_of(":");
				pos2 = s.size();
				s.substr(pos, pos2);

				tcol.SetType(s);
			}

			else
			{
				pos = s.find_first_of(":");
				s.substr(0, pos);
				tcol.SetTitle(s);
			}
		}

		cols.push_back(tcol);		 
		//cout << cols.at(i) << endl; 

	}

	//for (auto it = fData.begin(); it != fData.end(); it++)
	//{
	//	for (auto jt = it->begin(); jt != it->end(); jt++)
	//	{
	//		if (it == 0)
	//		{
	//			continue;	//already have the cols filled with titles and types so we don't need the first element of the vector here
	//		}

	//		if (*jt == "int")
	//		{
	//			
	//		}
	//	}

	//}
	

}

vector<DataColumn> Table::GetCols()
{
	return this->cols; 
}

vector<DataRow> Table::GetRows()
{
	return this->rows; 
}

void Table::SetKey(string primary_key)
{
	this->primary_key.push_back(primary_key);
}

vector<string> Table::GetKey()
{
	return this->primary_key; 
}
