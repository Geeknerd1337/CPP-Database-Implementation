#pragma once
#include "includes.h"

/// <summary>
/// This is a struct which defines the data that a column can hold. It has both a string and an integer.
/// </summary>
struct Data {
	int i;
	string s;
};

/// <summary>
/// This class is what gets stored into rows and contains a data type and a piece of data.
///  Since, as per Dr. Shirvani's specifications, the only kind of data types we will need are ints and 
/// strings, we can store the data as a string and cast to integer whenever we get the data.
/// </summary>
class DataColumn {
public:
	/// <summary>
	/// Initialize this column with a data type and a data struct, this will be populated with the kind of data needed for our tables.
	/// </summary>
	/// <param name="type">The type of data, either a str or an int</param>
	/// <param name="data">The actual data struct containing the relevant data</param>
	DataColumn(string type, Data data);
	/// <summary>
	/// The data type, either a string or an int
	/// </summary>
	string type;
	/// <summary>
	/// The struct which holds our data, either a string or an int
	/// </summary>
	Data data;

	template<typename T>
	T GetData();

};


