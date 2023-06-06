// Tools Class Library (Version:BETA-0.0.1.5599 NOT RELEASE) INNER VERSION
// ALPHA TEST
// PUBLISH BY 404 Software Studio https://www.dofozero.top
// TPCL Copyright (C) 2023-2024 Cloudwhile. All rights reserved.
// Author: Cloudwhile  <whitecat.this@gmail.com>
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http ://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// Description:



// Create:2023.5.23

#include "tools.h"
#include "readini.h"





#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <Windows.h>






#define INIFILE "config.ini"



using namespace std::chrono;
using namespace stdini;








//Check config

int stdtool::tools::readini()
{
	RCG ri;
	bool ret = ri.ReadConfig(INIFILE);
	if (ret == false) {
		cout << "Cannot read the config file :\t" << INIFILE << "\nUsing default config." << endl;
		return DEFAULT;
	}
	string i = ri.ReadString("NOTICE_OUTPUT", "Config", "");
	if (i == "DEFAULT" || "default") {
		return DEFAULT;
	}
	else if (i == "NONOTICE" || "nonotice") {
		return NONOTICE;
	}
	else if (i == "NOANY" || "noany") {
		return NOANY;
	}
	else {
		return DEFAULT;
	}
}




void stdtool::tools::time_count()
{
	timestramp_tmp = stdtool::tools::get_time();
	time_num = 0;
	time_num++;

	timestramp[time_num] = *timestramp;
}

stdtool::tools::tools()
{
	
	
}

stdtool::tools::~tools()
{
}

char* stdtool::tools::get_time()
{
	system_clock::time_point now = system_clock::now();

	// The number of nanoseconds from 1970-01-01 00:00:00.
	chrono::nanoseconds d = now.time_since_epoch();
	//cout << "current nanoseconds: " << d.count() << endl;

	// Convert to microseconds, loss of accuracy.
	chrono::microseconds mcrosec = chrono::duration_cast<chrono::microseconds>(d);
	//cout << "current microseconds: " << mcrosec.count() << endl;

	// Convert to milliseconds.
	chrono::milliseconds millsec = chrono::duration_cast<chrono::milliseconds>(d);
	//cout << "current milliseconds: " << millsec.count() << endl;

	// Convert to seconds.
	chrono::seconds sec = chrono::duration_cast<chrono::seconds>(d);
	//cout << "current seconds: " << sec.count() << endl;

	// Convert to minutes.
	chrono::minutes minutes = chrono::duration_cast<chrono::minutes>(d);
	//cout << "current minutes: " << minutes.count() << endl;

	// Convert to hours.
	chrono::hours hours = chrono::duration_cast<chrono::hours>(d);
	//cout << "current hours: " << hours.count() << endl;

	// Convert to day.
	typedef chrono::duration<int, ratio<24 * 60 * 60>> Day;
	Day days = chrono::duration_cast<Day>(d);
	//cout << "current days: " << days.count() << endl;

	// Converts to type time_t in ctime.
	time_t tt = system_clock::to_time_t(now);

	// Output time.
	auto timed = ctime(&tt);
	i = 0;
	while (timed[i] != '\n') {
		i++;
	}
	timed[i] = '\0';
	return timed;
}

ifstream ifs;
ofstream ofs;





//string to LPCWSTR Function

LPCWSTR stringToLPCWSTR(string origin)
{
	size_t origsize = origin.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (origin.length() - 1)];
	mbstowcs_s(&convertedChars, wcstring, origsize, origin.c_str(), _TRUNCATE);
	return wcstring;
}





//Write File Function
bool stdtool::tools::write_file(char* FilePath, char* STR)
{
	notice_str = (string)"[" + FilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(FilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL,NSTR , TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(FilePath, ios_base::out | ios_base::app);
	ofs << STR << '\n';
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete cache
	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::write_file(string cFilePath, string CSTR)
{
	notice_str = (string)"[" + cFilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(cFilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(cFilePath, ios_base::out | ios_base::app);
	ofs << CSTR << '\n';
	ofs.close();

	//delete cache
	cout << "File Output Successfully" << endl;

	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::write_file(char* FilePath, string CSTR)
{
	notice_str = (string)"[" + FilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	ifs.open(FilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(FilePath, ios_base::out | ios_base::app);
	ofs << CSTR << '\n';
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete
	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::write_file(string cFilePath, char* STR)
{
	notice_str = (string)"[" + cFilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(cFilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(cFilePath, ios_base::out | ios_base::app);
	ofs << STR << '\n';
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete cache
	delete NSTR;
	NSTR = nullptr;

	return false;
}




void stdtool::tools::get_pwd(string& str, int size)
{
	char c;
	int count = 0;
	char* password = new char[size];
	while ((c = getch()) != '\r') {

		if (c == 8) {
			if (count == 0) {
				continue;
			}
			putchar('\b');
			putchar(' ');
			putchar('\b');
			count--;
		}
		if (count == size - 1) {
			continue;
		}
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			putchar('*');
			password[count] = c;
			count++;
		}
	}
	password[count] = '\0';
	str = password;
	delete[] password; // delete cache
	cout << endl;
}



