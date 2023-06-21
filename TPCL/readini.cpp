#include "readini.h"
#include <fstream>
#include <stdlib.h>

namespace stdini
{

	bool RCG::IsSpace(char c)
	{
		if (' ' == c || '\t' == c)
			return true;
		return false;
	}

	bool RCG::IsCommentChar(char c)
	{
		switch (c) {
		case '#':
			return true;
		default:
			return false;
		}
	}

	void RCG::Trim(std::string& str)
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

	bool RCG::AnalyseLine(const std::string& line, std::string& section, std::string& key, std::string& value)
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

	bool RCG::ReadConfig(const std::string& fileName)
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

	std::string RCG::ReadString(const char* section, const char* item, const char* default_Value)
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
			//printf("111");
			return def;
		}
		k_v = it->second;
		it_item = k_v.find(tmp_i);
		if (it_item == k_v.end())
		{
			//printf("222");
			return def;
		}
		return it_item->second;
	}

	int RCG::ReadInt(const char* section, const char* item, const int& default_Value)
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

	float RCG::ReadFloat(const char* section, const char* item, const float& default_Value)
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
}