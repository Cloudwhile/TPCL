// Tools Class Library (Version:BETA-0.0.1.5589 NOT RELEASE) INNER VERSION
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
#pragma once


#ifndef ERRORM_H
#define ERRORM_H



#include<iostream>


using namespace std;
typedef const int DEFINE;

namespace err {
	class error {
		//system code

		DEFINE FRW_FATAL_ERROR = 1;
		DEFINE OVC_FATAL_ERROR = 2;
		DEFINE ARU_FATAL_ERROR = 3;
		DEFINE UCV_FATAL_ERROR = 4;
		DEFINE SYS_FATAL_ERROR = 5;
		DEFINE CAC_FATAL_ERROR = 6;
	public:
		//public code

		DEFINE WARNING = 7;
		DEFINE ERROR = 8;
		DEFINE FATAL = 9;

		void write_log();
	};
}









#endif