#include "includes.h"
#include "TableFactory.h"
#include "table.h"

TableFactory::TableFactory() {

}

unique_ptr<table> TableFactory::CreateTable(string file, string name) {
	return 0;
}

void TableFactory::InitializeSchema() {
    ifstream input_from_file("data/tables_schema.csv");

    cout << endl << "-------------------------------------------- " << endl;
    string line;

    while (getline(input_from_file, line)) {

        line += ",";

        stringstream ss(line);

        string word;

        vector<string> words;

        while (getline(ss, word, ',')) {

            words.push_back(word);
            cout << word << "  ";
        }

        schemaData.push_back(words);
        //cout << " --> number of cols : " << words.size() << endl;
        for (auto c : words) {
            std::cout << c << ' ';
        }
        cout << endl;
    }
}