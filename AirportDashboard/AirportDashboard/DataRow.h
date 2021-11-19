#pragma once
#include "includes.h"
#include "DataColumn.h"

using namespace std;

/// <summary>
/// This is a class which will hold a hash of columns
/// </summary>
class DataRow : public Table , public DataColumn
{

private:
	vector<string> sData;
	vector<int> iData;
	IntChainHash chRow; 
	IntLinHash lhRow; 
	IntQuadHash qhRow; 

public:
  DataRow();

  void sPop(/*vector<string> sData*/);
  void iPop(/*vector<int> iData*/);
  
  void PushData(); 

};
