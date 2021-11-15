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
	string type;
	Data data;

};


