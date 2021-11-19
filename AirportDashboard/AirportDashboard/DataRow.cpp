#include "includes.h"
#include "DataRow.h"
#include "TableFactory.h"

DataRow::DataRow()
{

}

void DataRow::sPop(vector<string> sData)
{

}

void DataRow::iPop(vector<int> iData, DataColumn cols)
{
  iData.push_back(cols.i);
  //for(auto it = iData.begin(); it != iData.end(); it++)
  //{
  //  
  //}
}

void DataRow::PushData()
{

}