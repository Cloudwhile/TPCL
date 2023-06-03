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

	tool.write_file("DETAIL.txt", tool.get_time() + name + " " + pwd);
	
	erro.write_log(erro.WARNING, "DONE FININSH!");
	return 0;

}