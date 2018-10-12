/* Test Territory for Player part

*/

#pragma once
#include "vector"
#include "iostream"
#include "string"

using namespace std;

class Territory_Test {

private:
	string name;

public:
	Territory_Test();
	Territory_Test(string s);
	void setname(string s);
	string getname();

};