#include "SequenceAnalyzer.h"
#include <fstream>
#include <iostream>


sequence_table* SequenceAnalyzer::divide_by_thread(const char* filename)
{
	std::ifstream in;
	char buffer[MAXBUFFER];
	struct contents tmp;
	std::string str;
	int num_line=0;
	sequence_table* table = new sequence_table;
	in.open(filename);
	while(!in.eof())
	{
		in.getline(buffer, MAXBUFFER);
		str = buffer;
	//delimeter process
	//std::cout<<str2<<std::endl;
		num_line++;
		size_t pos = str.find_first_of(del.c_str());
		int num_thread = atoi(str.substr(0,pos).c_str() );
		str = str.substr(pos+1 ); 
		pos = str.find("(");
		str = str.substr(0, pos);
	
		tmp.pos = num_line;
		tmp.body = str;
		(*table)[num_thread].push_back(tmp);

	}

	in.close();
	return table;
}	
void SequenceAnalyzer::print_sequence_table_into_file(sequence_table& table, const char* prefix_filename )
{
	std::ofstream out;
	std::string filename;
	for(sequence_table::iterator it = table.begin();  it!= table.end(); it++)
	{
		filename = prefix_filename;
	   	filename += std::to_string(it->first);
		out.open(filename.c_str());
		std::vector<struct contents >& c = it->second;
		for(std::vector<struct contents>::iterator it_v = c.begin(); it_v!= c.end(); it_v++)
			out<< it_v->body <<std::endl;
		out.close();
	}
}

void SequenceAnalyzer::compare(const sequence& s1, const sequence& s2)
{
	int i=0;
	int comp_size = s1.size() < s2.size(); 
	int size = comp_size ? s1.size(): s2.size();
	
	for(int i=0; i< size ; i++)
	{
		if( s1[i].body != s2[i].body)
		{
			std::cout<<s1[i].pos <<" : <<< "<< s1[i].body<< std::endl;
			std::cout<<s2[i].pos <<" : >>> "<< s2[i].body<< std::endl;
			return ;
		}
	}

	if(comp_size < 0 ) 
		std::cout<< "left sequence is subset of right sequence"<<std::endl;
	else if(comp_size >0)
		std::cout<<"right sequence is subset of left sequence"<<std::endl;
	else
		std::cout<<"exactly equal sequence"<<std::endl;


}


