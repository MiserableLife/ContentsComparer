#include "SetAnalyzer.h"
#include <vector>
#include <map>
#include <fstream>


int SetAnalyzer::read_with_delimeter(std::set<std::string>& filtered_set, const char* filename, bool append)
{
	std::ifstream in; 
	char buffer[255];

	if(!append)
		filtered_set.clear();
	in.open(filename);
	while(!in.eof())
	{
		std::vector<std::string> temp_storage;
		in.getline(buffer, 255);
		//delimeter process
		std::string str = buffer;
		std::size_t prepos=0, pos = str.find_first_of(del.c_str());
		while(pos != std::string::npos)
		{
			temp_storage.push_back(str.substr(prepos, pos-prepos));
			prepos = pos+1;
			while( ( pos = str.find_first_of(del.c_str(),pos+1)) != std::string::npos )
				if( pos != prepos) 
					break;
				else
					prepos = pos+1;
		}
		temp_storage.push_back(str.substr(prepos, pos-prepos));
		str="";
		for(std::vector<std::string>::iterator it= temp_storage.begin(); it!= temp_storage.end(); it++)
			str += *it + " ";
		//delimeter process end

		filtered_set.insert(str);
	}
	in.close();
	return 0;
}
std::set<std::string>* SetAnalyzer::get_diffset(const std::set<std::string>& set1, const std::set<std::string>& set2)
{
	std::set<std::string>* diff1_2 = new std::set<std::string>;
	//set1 - set2 
	*diff1_2 = set1;
	for(std::set<std::string>::iterator it = set2.begin(); it!= set2.end(); it++)
		diff1_2->erase(*it);
	return diff1_2;
}

void analyze_with_key(const std::set<std::string>& diff1_2, const std::set<std::string>& diff2_1)// developing.... 
{
	std::map<std::string, std::string > orghash;
	for(std::set<std::string>::iterator it = diff1_2.begin(); it!= diff1_2.end(); it++)
	{
		std::string str = *it;
		std::size_t pos = str.find_first_of(" ");
		orghash[str.substr(0,pos)] = str.substr(pos+1);
	}
	for(std::set<std::string>::iterator it = diff2_1.begin(); it!= diff2_1.end(); it++)
	{
		std::string str = *it;
		std::size_t pos = str.find_first_of(" ");
		if(!orghash[str.substr(0,pos)].empty())
		{
			std::string outputstr="";
			std::cout<< str.substr(0,pos)<< " " <<orghash[str.substr(0,pos)]<<std::endl;
			for(int i=0; i<pos+1; i++)
				outputstr += " ";
	
			str = orghash[str.substr(0,pos)];
			std::size_t prepos=0, pos = str.find_first_of(" ");
			while(pos != std::string::npos)
			{
			
			str.substr(prepos, pos-prepos);
			prepos = pos+1;
//		pos = str.find_first_of(" \t",pos+1);
			while( ( pos = str.find_first_of(" \t",pos+1)) != std::string::npos )
				if( pos != prepos) 
					break;
				else
					prepos = pos+1;
			}
	
		}
	}


}


