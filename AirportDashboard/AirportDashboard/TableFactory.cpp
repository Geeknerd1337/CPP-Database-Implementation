#include "includes.h"
#include "TableFactory.h"
#include "table.h"

TableFactory::TableFactory() {

}

unique_ptr<table> TableFactory::CreateTable(string file, string name) {
	return 0;
}

vector<string> TableFactory::FindSchema(string table) {
    for (int i = 0; i < schemaData.size(); i++) {
        string t = schemaData.at(i).at(0);
        if (t.compare(table) == 0) {
            return schemaData.at(i);
        }
    }
    
}

void TableFactory::PrintSchemaData() {
    cout << endl << "-------------------------------------------- " << endl;

    //Double for loop over the vector
    for (int i = 0; i < schemaData.size(); i++) {
        vector<string> vec = schemaData.at(i);
        for (int j = 0; j < vec.size(); j++) {
            //Lets do a little extra formatting to make sure it looks real nice
            string s = vec.at(j);
            if (s.length() < 10) {
                for (int b = 0; b < (10 - s.length()) + 1; b++) {
                    s += " ";
                }
            }

            if (s.length() >= 10) {
                s = s.substr(0, 10);
            }

            cout << "|" << s << "|\t";
        }
        cout << endl;
    }

    cout << endl << "-------------------------------------------- " << endl;

}

void TableFactory::InitializeSchema() {
    //Load the schema file
    ifstream input_from_file("data/tables_schema.csv");

    //Where we store the line
    string line;

    while (getline(input_from_file, line)) {

        line += ",";

        stringstream ss(line);

        string word;

        vector<string> words;

        //Delimit the list of commas to get the words and push them to the words vector
        while (getline(ss, word, ',')) {

            words.push_back(word);
        }
        //Push the vector of words to the schema data 2D vecttor
        schemaData.push_back(words);

    }
}
