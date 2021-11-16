#pragma once
#include "includes.h";

/// <summary>
/// This is a class which holds a vector of data rows and a vector for the primary key.
/// TODO: Create a third vector of columns with empty data which is used as a template when populating the rows.
/// </summary>
class table {
public:
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
	/// This is a vector containing our data rows and is what gets accessed for insertions, deletions, and updates.
	/// </summary>
	vector<DataRow> rows;
	/// <summary>
	/// This is a function which every derived class from table will implement. Each derived table may use a different hashing 
	/// type, and thus will store each piece of data differently, but will ultimately be accessed in the same way.
	/// TODO: Move this function to the data row class
	/// </summary>
	/// <param name="d">The data we want to populate into a givn column</param>
	virtual void PushData();


private:
	
};