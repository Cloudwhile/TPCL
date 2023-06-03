#pragma once
#ifndef READINI_H_
#define READINI_H_
#include <string>
#include <map>
namespace stdini
{
	class RCG
	{
	public:
		RCG()
		{
		}
		~RCG()
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

	private:
		//std::map<std::string, std::string> settings_;
		std::map<std::string, std::map<std::string, std::string> >settings_;
	};
}
#endif