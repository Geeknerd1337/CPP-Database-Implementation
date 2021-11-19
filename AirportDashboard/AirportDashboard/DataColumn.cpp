#include "DataColumn.h"
#include "table.h"

DataColumn::DataColumn()
{
	this->type = " ";
	this->title = " ";
	this->index = 0;
	this->data.i = 0;
	this->data.s = " ";
}

void DataColumn::SetData(Data data)
{
	this->data = data; 
}

Data DataColumn::GetData()
{
	return this->data; 
}

DataColumn::DataColumn(string type, Data data) {
	this->type = type;
	this->data = data;
}

void DataColumn::SetIndex(int index)
{
	this->index = index;
}

int DataColumn::GetIndex()
{
	return this->index;
}

//template<typename T>
//T DataColumn::GetData() {
//	if (type.compare("str") == 0) {
//		return data.s;
//	}
//
//	if (type.compare("int") == 0) {
//		return data.i;
//	}
//}

void DataColumn::SetTitle(string title)
{
	this->title = title; 
}

string DataColumn::GetTitle()
{
	return this->title;
}

void DataColumn::SetType(string type)
{
	this->type = type; 
}

string DataColumn::GetType()
{
	return this->type; 
}

void DataColumn::PushData()
{
	Table t; 
	DataColumn d; 
	vector<vector<string>> fTemp; 
	int ctr = 0;

	fTemp = t.GetFileData(); 
	d = t.GetCols; 
	for (auto it = fTemp.begin(); it != fTemp.end(); it++)
	{
		for (auto jt = it->begin(); jt != it->end(); jt++)
		{
			if (ctr == 0)
			{
				continue;	//already have the cols filled with titles and types so we don't need the first row of the vector here
			}

			if (d.at(ctr).GetType() == "int")			//converts string to an integer if the type in our cols calls for it to be a string
			{
				data.i = stoi(*jt); 
			}
			else if (d.at(ctr).GetType() == "str")		//stores string into cols if that is the type it calls for 
			{
				data.s = *jt; 
			}
		}

		ctr++; 

	}

}

void DataColumn::ColPop()
{
	Table temp;
	vector<DataColumn> tcol; 
	tcol = temp.GetCols();
	vector<string> stemp; 


}