#include "includes.h"
#include "table.h"


/// <summary>
/// This is going to use a programming pattern called the factory pattern
/// Basically, what this is is we will use it to create out objects and initialize schema. 
/// </summary>
class TableFactory {
public:
	/// <summary>
	/// Constructor for table factory
	/// </summary>
	TableFactory();


	/// <summary>
	/// This will take in a table name and CSV file and create the appropriate table accordingly
	/// The reason this is a unique_ptr is so we can return derived classes from table from this method
	/// makes our job a lot easier rather than having to create a million methods to return each type of table
	/// </summary>
	/// <param name="file">The CSV file for the table's schema</param>
	/// <param name="name">The name of the table, this is going to be used to figure out what to construct.</param>
	/// <returns></returns>
	unique_ptr<table> CreateTable(string file, string name);

private:

};