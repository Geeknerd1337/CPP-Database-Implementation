#pragma once
#include "includes.h";


class table {
public:
	vector<string> primary_key;
	vector<DataRow> rows;
	virtual void PushData(Data d);
private:
	
};