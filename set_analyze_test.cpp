#include <iostream>
#include "SetAnalyzer.h"



int main(int argc, char** argv)
{
	if(argc <3 )
		return 1;
	char* file1 = argv[1];
	char* file2 = argv[2];
	SetAnalyzer sa;
	std::set<std::string> set1, set2;
	sa.read_with_delimeter(set1, file1);
	sa.read_with_delimeter(set2, file2);

	std::set<std::string>* diff1_2 = sa.get_diffset(set1, set2);
	std::set<std::string>* diff2_1 = sa.get_diffset(set2, set1);
	std::cout<<"only on "<<file1<<"  contents"<<std::endl;
	for(std::set<std::string>::iterator it = diff1_2->begin(); it!= diff1_2->end(); it++) 
		std::cout<<*it<<std::endl;

	std::cout<<std::endl<<std::endl;
	std::cout<<"only on "<<file2<<"  contents"<<std::endl;
	for(std::set<std::string>::iterator it = diff2_1->begin(); it!= diff2_1->end(); it++) 
		std::cout<<*it<<std::endl;

	delete diff1_2;
	delete diff2_1;

	return 0;	
}
