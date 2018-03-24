#ifndef SETANALYZER_H_
#define SETANALYZER_H_

#include <string>
#include <set>



class SetAnalyzer
{
private:
//	std::map<std::string, std::string> orghash;
	std::string del; 
public:
	SetAnalyzer() : del("\t")
	{
	};
	inline void setdelimeter(const char* delimeter)
	{
		del = delimeter;
	}
	int read_with_delimeter(std::set<std::string>& filtered_set, const char* filename, bool append=false);
	std::set<std::string>* SetAnalyzer::get_diffset(const std::set<std::string>& set1, const std::set<std::string>& set2);
	

};



#endif

