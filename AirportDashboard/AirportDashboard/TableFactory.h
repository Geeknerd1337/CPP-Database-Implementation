#include "includes.h"
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

	template <typename T>
	/// <summary>
	/// This will take in a table name and CSV file and create the appropriate table accordingly
	/// The T here is so we can return any type, casts and conversions will need to be made but this allows us to basically return any table
	/// Only doing this since Shirvani insists that every table be its own class. Which is dumb, but who asked me. 
	/// </summary>
	T CreateTable();
private:

};