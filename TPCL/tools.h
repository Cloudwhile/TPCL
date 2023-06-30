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



#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>




using namespace std;




namespace stdtool {
	class tools {
		int i = 0;
		int time_num = 0;


		const int DEFAULT = 1;
		const int NONOTICE = 2;
		const int NOANY = 3;


		string notice_str;
		string log_str;
		char* timestramp_tmp;
		char* timestramp[];


		//private function

		int readini();
		void time_count();
	public:
		tools();
		~tools();
		char* get_time();
		//write_file function
		bool write_file(char* FilePath, char* STR);
		bool write_file(string cFilePath, string CSTR);
		bool write_file(char* FilePath, string CSTR);
		bool write_file(string cFilePath, char* STR);

		//password for console
		static void get_pwd(string& str, int size);
	};
}


#endif