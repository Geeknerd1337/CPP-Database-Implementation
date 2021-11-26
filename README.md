# CPP-Database-Implementation
# Airport Dashboard
 ## System Diagram
 ![System Diagram](https://github.com/Geeknerd1337/CPP-Database-Implementation/blob/main/airport.png?raw=true)
 ## Milestone 1
 
 ## Milestone 2
 ## _INSERT Command_
 ### _Description_
 Insert Function inserts a record into a table in the database. Technically this function inserts a Row object into the list of of row objects in a Table object. As per the given instructions the function takes in a key,value tuple and the Table name in which the record is to be inserted. Afterwards we check if there is any record in the Table against the given key. In case we don't find any record against the given key then a new DataRow object is created. For each column value we check if the value is a string or an integer (from the given schema file) and as per the data type the element is stored in the DataRow object's string or integer vector.
 ### _Data Storage Mechanism_
 The system reads the command from the _input.txt_ file. Stores it in a string. Then this string is parsed and we separate out the key,value tuple from the command read. After words the the key value tuple is parsed and the values are stored in vector of type string. This string is passed to a function called _KeyExists_. This function checks if the key exists in the Table by traversing the DataRow objects of the subject Table object. In case the key already exists in the table then error is prompted on the CLI. Now, we check if the number of columns of the subject table and the number of columns provided in the key,value tuple are equal. In case if we have more columns in key value tuple, then an error message is prompted on CLI and the insert process is aborted. However, if number of columns in key,value tuple is less than the number of columns of the subject Table(as per schema) then we proceed with the insert function process and DataRow object's string and integer vectors are populated with the values of the new record and for the missing column values we use Null. Once, the DataRow object is populated we push the new object into the DataRow vector of the table and call the InsertItem function. 
 ### _Functionality_
 This function inserts data into the Table existing in the program memory. The mechanism for insertion to the table is simple. At first we separate out the column values provided in the command and the Table name provided. Then we compare # of columns provided in the command with the number of columns of the table as per given schema. Column count mismatch anomalies are reported using the _Alert Message_ function. This function takes in TableName, ErrorMessage and given Command as paramters and displays an error message on CLI. If there are no column count mismatch anomalies then we check if the given key in the key,value tuple already exists in the Table. If the key exists the an error message is displayed otherwise we create and populate a DataRow object and Call the _InsertItem_ function to insert data into the Table in our program's memory. Once table is updated we then update the corresponding excel file for that table by calling the _WriteToCsv_ function. This functions takes in 2 parameters filename & vector containing column values for the new record. This functions writes the data into the excel file.    
 
 ## _UPDATE Command_
 ### _Description_
 Update Function updates a record in a table in the database. Technically this function updates a Row object pointed by the provided key in the command. As per the given instructions the function takes in a key,value tuple and the Table name in which the record is to be updated. Afterwards we check if there is any record in the Table against the given key. In case we find a record against the given key then a new DataRow object is updated with the column values given in the command. For each column value we check if the value is a string or an integer (from the given schema file) and as per the data type the element is stored in the DataRow object's string or integer vector. 
 ### _Data Storage Mechanism_
 The system reads the command from the _input.txt_ file. Stores it in a string. Then this string is parsed and we separate out the key,value tuple from the command read. After words the the key value tuple is parsed and the values are stored in vector of type string. This string is passed to a function called _KeyExists_. This function checks if the key exists in the Table by traversing the DataRow objects of the subject Table object. In case the key exists in the table then we proceed with the update function. Now, we check if the number of columns of the subject table and the number of columns provided in the key,value tuple are equal. In case if we have more columns in key value tuple, then an error message is prompted on CLI and the insert process is aborted. However, if number of columns in key,value tuple is less than the number of columns of the subject Table(as per schema) then we proceed with the insert function process and DataRow object's string and integer vectors are populated with the values of the new record and for the missing column values we use Null. Once, the DataRow object is populated we replace the new object into the DataRow vector of the table and call the InsertItem function.
 ### _Functionality_
 This function updates data into the Table existing in the program memory. The mechanism for updation to the table is simple. At first we separate out the column values provided in the command and the Table name provided. Then we compare # of columns provided in the command with the number of columns of the table as per given schema. Column count mismatch anomalies are reported using the _Alert Message_ function. This function takes in TableName, ErrorMessage and given Command as paramters and displays an error message on CLI. If there are no column count mismatch anomalies then we check if the given key in the key,value tuple already exists in the Table. If the key exists then create and populate a DataRow object. We replace the old DataRow object and Call the _InsertItem_ function to replace data in the Table in our program's memory. Once table is updated we then update the corresponding excel file for that table by calling the _UpdateCsv_ function. This functions takes in 3 parameters filename, row_id, vector containing column values for the new record . This functions updates the record in the excel file.
 
 ## _SELECT Command_
 ### _Description_
Selects columns of table based on a condition given in the command and the Table mentioned in the SELECT command. This function fetches data based on the provided filter/condition and displays those columns' data on CLI.
 ### _Data Storage Mechanism_
 All the data correponding to the rows that meet the specified filtering criteria are is kept in a vector of strings where each string represents a row.
 ### _Functionality_
 The function parses the given command and separates out the table name and filtering column value. Then we traverse the string and int vectors for each DataRow object of the subject table. If the filtering crieria is matched i.e. the filtering value is found in the string or int vector for a DataRow object then all the data of that DataRow object is converted/casted into a single string which represnts that row of table. This string is pushed back into the vector of strings we used for data storage in this function. Once we traverse all the DataRow objects we have a vector containing all the rows of table matching our filtering criteria. In case we don't find any rows fulfilling the criteria an error message is prompted. However, if find rows matching the filtering criteria then those rows are displayed on the CLI by calling _PrintTableRow_ function.
