#include <iostream>

#include "tools.h"
#include "errorm.h"


using namespace std;
using namespace stdtool;
using namespace err;
int main() {
	tools tool;
	error erro;

	string name;
	string pwd;

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your password: ";

	tool.get_pwd(pwd, 100);

	tool.write_file("DETAIL.txt", tool.get_time() + (string)" " + name + " " + pwd);
	
	erro.write_log("DONE FININSH!",erro.WARNING);
	return 0;

}