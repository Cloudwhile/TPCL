// Tools Class Library (Version:ALPHA-0.0.1.8658) ALPHA TEST VERSION
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



#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <map>
#include <vector>




using namespace std;




namespace stdtool {
	typedef const int INT;
	INT CVM = 1;
	INT ADM = 2;
	class tools {
	public:
		tools();
		~tools();
		char* getTime();
		//write_file function
    
		bool writeFile(const char* FilePath, const char* STR);
		bool writeFile(const string cFilePath, const string CSTR);
		bool writeFile(const char* FilePath, const string CSTR);
		bool writeFile(const string cFilePath, const char* STR);
		bool writeFile(const string cFilePath, const string CSTR, const int type);

		//password for console
		static void getPwd(string& str, int size);
		vector<string> readFile(const char* FilePath);

	private:
		int i = 0;
		int time_num = 0;


		const int DEFAULT = 1;
		const int NONOTICE = 2;
		const int NOANY = 3;


		string notice_str;
		string log_str;
		char* timestramp_tmp = {};
		char* timestramp[1000] = {};


		//private function

		int readini();
		void time_count();
		bool writeFile_q(const string cFilePath, string CSTR, const int type);
	};
}

namespace stdini
{
	class readConfig
	{
	public:
		readConfig()
		{
		}
		~readConfig()
		{
		}
		bool ReadConfig(const std::string& fileName);
		std::string ReadString(const char* section, const char* item, const char* default_Value);
		int ReadInt(const char* section, const char* item, const int& default_Value);
		float ReadFloat(const char* section, const char* item, const float& default_Value);
	private:
		bool IsSpace(char c);
		bool IsCommentChar(char c);
		void Trim(std::string& str);
		bool AnalyseLine(const std::string& line, std::string& section, std::string& key, std::string& value);
		//std::map<std::string, std::string> settings_;
    
		std::map<std::string, std::map<std::string, std::string> >settings_;
	};
}



namespace network {
	typedef int		BOOL;
	//typedef const string	WORD;

	typedef const char*		CWORD;
	typedef unsigned char       BYTE;
	typedef unsigned long       DWORD;


	class ftp {

	public:
		BOOL ftpUpload(CWORD ftpAddress, CWORD fileName, CWORD uploadStr);
		BOOL ftpDownload(CWORD ftpAddress, CWORD ftpFileName);
		BOOL ftpDownload(CWORD ftpAddress, CWORD ftpFileName, CWORD downloadName);

	private:
		BOOL ftpSave(CWORD fileName, BYTE* data, DWORD dataSize);
		BOOL ftpUrlCk(
			CWORD url,
			char* scheme,
			char* hostName,
			char* userName,
			char* pwd,
			char* urlPath,
			char* extraInfo,
			DWORD dwBufferSize);
		BOOL ftpDown(
			CWORD downloadUrl,
			BYTE** downloadData,
			DWORD* downloadDataSize);
		BOOL ftpUp(
			CWORD uploadUrl,
			BYTE* uploadData,
			DWORD uploadDataSize);
	};
}
#endif