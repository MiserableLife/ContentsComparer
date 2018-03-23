#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <map>


int main(int argc, char** argv)
{
	std::ifstream in; 
	if(argc <3 )
		return 1;
	char* file1 = argv[1];
	char* file2 = argv[2];
	char buffer[255];
	std::set<std::string> set1;
	std::set<std::string> set2;
	std::set<std::string> diff1_2;
	std::set<std::string> diff2_1;
	std::map<std::string, std::string> orghash;
	in.open(file1);
	while(!in.eof())
	{
		std::vector<std::string> temp_storage;
		in.getline(buffer, 255);
		//delimeter process
		std::string str = buffer;
		std::size_t prepos=0, pos = str.find_first_of(" \t");
		while(pos != std::string::npos)
		{
			temp_storage.push_back(str.substr(prepos, pos-prepos));
			prepos = pos+1;
			while( ( pos = str.find_first_of(" \t",pos+1)) != std::string::npos )
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
		
		set1.insert(str);
	}
	in.close();
	in.open(file2);
	while(!in.eof())
	{
		std::vector<std::string> temp_storage;
		in.getline(buffer,255);
	//delimeter process
		std::string str = buffer;
		std::size_t prepos=0, pos = str.find_first_of(" \t");
		while(pos != std::string::npos)
		{
			
			temp_storage.push_back(str.substr(prepos, pos-prepos));
			prepos = pos+1;
//			pos = str.find_first_of(" \t",pos+1);
			while( ( pos = str.find_first_of(" \t",pos+1)) != std::string::npos )
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
		
		set2.insert(str);
	}
	in.close();

	diff1_2 = set1;
	diff2_1 = set2;

	for(std::set<std::string>::iterator it = set1.begin(); it!= set1.end(); it++)
		diff2_1.erase(*it);
	for(std::set<std::string>::iterator it = set2.begin(); it!= set2.end(); it++)
		diff1_2.erase(*it);


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
//			pos = str.find_first_of(" \t",pos+1);
			while( ( pos = str.find_first_of(" \t",pos+1)) != std::string::npos )
				if( pos != prepos) 
					break;
				else
					prepos = pos+1;
		}
		temp_storage.push_back(str.substr(prepos, pos-prepos));
		
			

			std::cout<< 
		}
	}

	std::cout<<"only on "<<file1<<"  contents"<<std::endl;
	for(std::set<std::string>::iterator it = diff1_2.begin(); it!= diff1_2.end(); it++) 
		std::cout<<*it<<std::endl;

	std::cout<<std::endl<<std::endl;
	std::cout<<"only on "<<file2<<"  contents"<<std::endl;
	for(std::set<std::string>::iterator it = diff2_1.begin(); it!= diff2_1.end(); it++) 
		std::cout<<*it<<std::endl;



	return 0;	
}
