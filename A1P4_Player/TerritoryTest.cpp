#include "Territory_Test.h"

Territory_Test::Territory_Test() {
	this->name = "default";
}

Territory_Test::Territory_Test(string s) {
	this->name = s;
}

void Territory_Test::setname(string nam) {
	this->name = nam;
}

string Territory_Test::getname() {
	
	return this->name;
}