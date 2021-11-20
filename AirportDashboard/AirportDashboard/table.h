#pragma once
#include "includes.h"
#include "TableFactory.h"

/// <summary>
/// This is a class which holds a vector of data rows and a vector for the primary key.
/// TODO: Create a third vector of columns with empty data which is used as a template when populating the rows.
/// </summary>
class Table{
public:

	/// <summary>
	/// Empty constructor
	/// </summary>
	Table(); 
	/// <summary>
	/// This will set the table populated with a 2D vector of its "data" from the CSV file
	/// </summary>
	/// <param name="fileData"></param>
	Table(vector<vector<string>> fileData);
	
	/// <summary>
	/// This table takes in a vector of the databases schema then uses the file data to populate the tables rows with data rows
	/// It first initiates the schema then populates the data
	/// </summary>
	/// <param name="schema"></param>
	void PopulateTable(vector<string> schema);


	vector<vector<string>> GetFileData();

	vector<DataColumn> GetCols(); 
	vector<DataRow> GetRows(); 
	
	void AddKey(string primary_key);
	vector<string> GetKey(); 


private:
	/// <summary>
	/// Here is a quote from the Lab report:
	/// In each row: the first column is the name of the tables and the rest are data
	//elements.
	///▪ There is colon ‘:’ separator in each column. The key for each table
	///is defined by “k” followed by ‘:’ separator. Some tables may have
	///compound keys.
	///▪ The type of data will be either string or integer which is defined as
	///“:str” or “:int”.
	///
	/// In the real world, primary keys are the set of columns which make rows unique. Meaning that these 3 columns in each row
	/// will be a unique combination and cannot be repeated. This will be important for preventing duplicate insertions.
	/// </summary>
	vector<string> primary_key;
	/// <summary>
	/// This is a vector representing our database schema, it represents what our columns are and where in the relevant arrays within our data rows they exist
	/// </summary>
	vector<DataColumn> cols;
	vector<DataRow> rows; 

	vector<vector<string>> fileData; 

};
