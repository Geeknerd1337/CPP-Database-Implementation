#pragma once
#include "includes.h"

using namespace std;

/// <summary>
/// This is a class which will hold a hash of columns
/// </summary>
class DataRow
{

private:
	vector<string> sData;
	vector<int> iData;


public:
  DataRow();

  void sPop(/*vector<string> sData*/);
  void iPop(/*vector<int> iData*/);
  
  void PushData(); 

};
