#include "includes.h"
#include "TableFactory.h"
#include "table.h"
#include "DataColumn.h"

using namespace std; 


Table::Table() {

}



void Table::InitializeTableSchema(vector<string> schema) {
	//Keep two integers for the indices in the vectors on the data row class
	int strIndex = 0;
	int intIndex = 0;

	//First, we are going to go over the schema, create a data column and push it to our column vectors.
	//The reason we don't need to make this a pointer or worry about the new key word is push_back on vector
	//Will create copy automatically. We also add these to our primary key.
	for (int i = 0; i < schema.size(); i++) {
		//Store the current piece of 'schema' into a temporary string
		string str = schema[i];

		//Since the first item in the schema vector is the tables title, we can just set it based on the incoming vector
		if (i == 0) {
			this->title = str;
		}
		else {
			//This is where the magic happens, we're going to get a string like this "ID:k:int" or this "Maker::str", and parse it into a
			//data column and push it to the columns vector. If it contains a :k: we will also push the title of that column to the primary_key
			//we are also going to keep track of the number of strings and ints so that we can set the desired index for the eventual vectors
			//in our datarow class.

			//Store the title of the column to a string by substringing it
			string title = str.substr(0, str.find_first_of(":"));

			//Now we can get the type pretty easy using basically the same method, excpept with the last instance of :
			string type = str.substr(str.find_last_of(":") + 1, str.length() - str.find_last_of(":"));

			//This is basically how we find if this row is a primary key or not, extremely simple way to check and we're just adding it to our primary key vector
			if (str.find(":k:") != -1) {
				primary_key.push_back(title);
			}

			//Bellow is where we finally add the columns to the column vector, an extremely simple operation and since columns is a vector we don't need to mess
			//with pointers since push back will create a copy of the data column

			//If our type is a string, increment the str index
			if (type.compare("str") == 0) {
				//cout << "COLUMN TITLE: '" << title << "' COLUMN TYPE: '" << type << "'" << "\tSTR INDEX: " << strIndex << endl;
				DataColumn d(type, title, strIndex);
				columns.push_back(d);
				strIndex++;
			}

			//If our type is an int, increment the integer index
			if (type.compare("int") == 0) {
				//cout << "COLUMN TITLE: '" << title << "' COLUMN TYPE: '" << type << "'" << "\tINT INDEX: " << intIndex << endl;
				DataColumn d(type, title, intIndex);
				columns.push_back(d);
				intIndex++;
			}
		}

	}
}

string Table::PadString(string s, int i) {
	if (s.length() < i) {
		s.append(i - s.length(), ' ');
	}

	if (s.length() > (i - 1)) {
		s = s.substr(0, i);
	}

	return s;

}

void Table::PrintTable() {
	cout << "TABLE: " << title << endl << endl;

	for (int i = 0; i < columns.size(); i++) {
		//Lets do a little extra formatting to make sure it looks real nice
		string s = columns.at(i).GetTitle();
		cout << "|" << PadString(s, 10) << "|";
	}

	cout << endl;

	for (int j = 0; j < rows.size(); j++) {
		DataRow d = rows.at(j);
		for (int k = 0; k < columns.size(); k++) {
			DataColumn c = columns.at(k);
			if (c.GetType().compare("str") == 0) {
				cout << "|" << PadString(d.strs.at(c.GetIndex()), 10) << "|";
			}

			if (c.GetType().compare("int") == 0) {
				string num = to_string(d.ints.at(c.GetIndex()));
				cout << "|" << PadString(num, 10) << "|";
			}
		}
		cout << endl;

	}

	cout << endl << endl << endl << endl;
}

void Table::InitializeTableData(vector<vector<string>> data) {
	//First we iterate through the given data file
	for (int i = 0; i < data.size(); i++) {
		//Then we loop over the inviddual items in the columns
		//Instantiate a data row
		DataRow row;

		//A temporary variable for if we can push or not
		bool b = false;

		for (int j = 0; j < data.at(i).size(); j++) {
			//We don't use the first row since it contains column headers
			if (i != 0) {
				//Set b to true so we don't push an empty row, this is the wrong way to do it, but whatever.
				b = true;

				//Storing index for fun
				int index = j;
				//Get the relevant datacolumn at our position in the row
				DataColumn d = columns.at(j);
				//Get that data columns type
				string type = d.GetType();
				
				//Get the invidual item in the row
				string item = data.at(i).at(j);

				//If this columns type is a string, push it to the rows string vector
				if (type.compare("str") == 0) {
					row.strs.push_back(item);
				}

				//Otherwise, if it is an int, push it to the rows integer vector
				if (type.compare("int") == 0) {
					int itemInt = stoi(item);
					row.ints.push_back(itemInt);
				}
			}
		}

		//If the row we want to push isn't empty.
		if (b) {
			//Temporarily pushing this to a rows vector. 
			rows.push_back(row);
		}

	}
}





vector<DataColumn> Table::GetCols()
{
	return this->columns; 
}

vector<DataRow> Table::GetRows()
{
	return this->rows; 
}

void Table::AddKey(string primary_key)
{
	this->primary_key.push_back(primary_key);
}

vector<string> Table::GetKey()
{
	return this->primary_key; 
}
