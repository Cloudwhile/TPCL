// Tools Class Library (Version:ALPHA-0.0.1.6001) ALPHA TEST VERSION
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





#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <Windows.h>






#define INIFILE "config.ini"



using namespace std::chrono;








//Check config

int stdtool::tools::readini()
{
	stdini::readConfig ri;
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
	timestramp_tmp = stdtool::tools::getTime();
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

char* stdtool::tools::getTime()
{
	system_clock::time_point now = system_clock::now();

	chrono::nanoseconds d = now.time_since_epoch();

	chrono::microseconds mcrosec = chrono::duration_cast<chrono::microseconds>(d);

	chrono::milliseconds millsec = chrono::duration_cast<chrono::milliseconds>(d);

	chrono::seconds sec = chrono::duration_cast<chrono::seconds>(d);

	chrono::minutes minutes = chrono::duration_cast<chrono::minutes>(d);

	chrono::hours hours = chrono::duration_cast<chrono::hours>(d);

	typedef chrono::duration<int, ratio<24 * 60 * 60>> Day;
	Day days = chrono::duration_cast<Day>(d);

	time_t tt = system_clock::to_time_t(now);

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
bool stdtool::tools::writeFile(char* FilePath, char* STR)
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

bool stdtool::tools::writeFile(string cFilePath, string CSTR)
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

bool stdtool::tools::writeFile(char* FilePath, string CSTR)
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

bool stdtool::tools::writeFile(string cFilePath, char* STR)
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

bool stdtool::tools::writeFile(string cFilePath, string CSTR, int type)
{
	if (type == 1) {
		writeFile_q(cFilePath, CSTR);
	}

	return false;
}


bool stdtool::tools::writeFile_q(string cFilePath, string CSTR) {
	time_count();
	ofs.open(cFilePath,ios_base::out | ios_base::app);
	ofs << CSTR;
	ofs.close();
	return false;
}



void stdtool::tools::getPwd(string& str, int size)
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



bool stdini::readConfig::IsSpace(char c)
{
	if (' ' == c || '\t' == c)
		return true;
	return false;
}

bool stdini::readConfig::IsCommentChar(char c)
{
	switch (c) {
	case '#':
		return true;
	default:
		return false;
	}
}

void stdini::readConfig::Trim(std::string& str)
{
	if (str.empty())
	{
		return;
	}
	int i, start_pos, end_pos;
	for (i = 0; i < str.size(); ++i) {
		if (!IsSpace(str[i])) {
			break;
		}
	}
	if (i == str.size())
	{
		str = "";
		return;
	}
	start_pos = i;
	for (i = str.size() - 1; i >= 0; --i) {
		if (!IsSpace(str[i])) {
			break;
		}
	}
	end_pos = i;
	str = str.substr(start_pos, end_pos - start_pos + 1);
}

bool stdini::readConfig::AnalyseLine(const std::string& line, std::string& section, std::string& key, std::string& value)
{
	if (line.empty())
		return false;
	int start_pos = 0, end_pos = line.size() - 1, pos, s_startpos, s_endpos;
	if ((pos = line.find("#")) != -1)
	{
		if (0 == pos)
		{
			return false;
		}
		end_pos = pos - 1;
	}
	if (((s_startpos = line.find("[")) != -1) && ((s_endpos = line.find("]"))) != -1)
	{
		section = line.substr(s_startpos + 1, s_endpos - 1);
		return true;
	}
	std::string new_line = line.substr(start_pos, start_pos + 1 - end_pos);
	if ((pos = new_line.find('=')) == -1)
		return false;
	key = new_line.substr(0, pos);
	value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));
	Trim(key);
	if (key.empty()) {
		return false;
	}
	Trim(value);
	if ((pos = value.find("\r")) > 0)
	{
		value.replace(pos, 1, "");
	}
	if ((pos = value.find("\n")) > 0)
	{
		value.replace(pos, 1, "");
	}
	return true;
}

bool stdini::readConfig::ReadConfig(const std::string& fileName)
{
	settings_.clear();
	std::ifstream infile(fileName.c_str());//The constructor calls open by default, so you can omit it
	//std::ifstream infile;
	//infile.open(fileName.c_str());
	//bool ret = infile.is_open()
	if (!infile) {
		return false;
	}
	std::string line, key, value, section;
	std::map<std::string, std::string> k_v;
	std::map<std::string, std::map<std::string, std::string> >::iterator it;
	while (getline(infile, line))
	{
		if (AnalyseLine(line, section, key, value))
		{
			it = settings_.find(section);
			if (it != settings_.end())
			{
				k_v[key] = value;
				it->second = k_v;
			}
			else
			{
				k_v.clear();
				settings_.insert(std::make_pair(section, k_v));
			}
		}
		key.clear();
		value.clear();
	}
	infile.close();
	return true;
}

std::string stdini::readConfig::ReadString(const char* section, const char* item, const char* default_Value)
{
	std::string tmp_s(section);
	std::string tmp_i(item);
	std::string def(default_Value);
	std::map<std::string, std::string> k_v;
	std::map<std::string, std::string>::iterator it_item;
	std::map<std::string, std::map<std::string, std::string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return def;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return def;
	}
	return it_item->second;
}

int stdini::readConfig::ReadInt(const char* section, const char* item, const int& default_Value)
{
	std::string tmp_s(section);
	std::string tmp_i(item);
	std::map<std::string, std::string> k_v;
	std::map<std::string, std::string>::iterator it_item;
	std::map<std::string, std::map<std::string, std::string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return default_Value;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return default_Value;
	}
	return atoi(it_item->second.c_str());
}

float stdini::readConfig::ReadFloat(const char* section, const char* item, const float& default_Value)
{
	std::string tmp_s(section);
	std::string tmp_i(item);
	std::map<std::string, std::string> k_v;
	std::map<std::string, std::string>::iterator it_item;
	std::map<std::string, std::map<std::string, std::string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return default_Value;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return default_Value;
	}
	return atof(it_item->second.c_str());
}
