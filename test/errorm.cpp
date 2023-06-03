/// Tools Class Library (Version:BETA-0.0.1.5589 NOT RELEASE) INNER VERSION
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


#include "errorm.h"

#include <fstream>
#include <Windows.h>
#include <ctime>


 

ifstream infs;
ofstream outfs;


void err::error::write_log()
{
	time_t now = time(nullptr);
	auto timec = ctime(&now);
	const string LOG_PATH = timec + (string)" " + "log.txt";


	outfs.open(LOG_PATH, ios_base::out);
	outfs.close();
}
