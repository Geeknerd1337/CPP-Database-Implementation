#include "DataColumn.h"


DataColumn::DataColumn(string type, Data data) {
	this->type = type;
	this->data = data;
}


template<typename T>
T DataColumn::GetData() {
	if (type.compare("str") == 0) {
		return data.s;
	}

	if (type.compare("int") == 0) {
		return data.i;
	}
}