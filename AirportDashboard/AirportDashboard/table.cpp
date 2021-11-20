#include "includes.h"
#include "TableFactory.h"
#include "table.h"
#include "DataColumn.h"

using namespace std; 


Table::Table() {

}

void Table::PopulateTable(vector<string> schema) {
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

			if (type.compare("str") == 0) {
				cout << "COLUMN TITLE: '" << title << "' COLUMN TYPE: '" << type << "'" << "\tSTR INDEX: " << strIndex << endl;
				strIndex++;
			}

			if (type.compare("int") == 0) {
				cout << "COLUMN TITLE: '" << title << "' COLUMN TYPE: '" << type << "'" << "\tINT INDEX: " << intIndex << endl;
				intIndex++;
			}

		}

	}
}

Table::Table(vector<vector<string>> fileData) {
	this->fileData = fileData;
}


vector<vector<string>> Table::GetFileData()
{
	return this->fileData; 
}


vector<DataColumn> Table::GetCols()
{
	return this->cols; 
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
