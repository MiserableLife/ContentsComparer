#include <iostream>
#include "SequenceAnalyzer.h"

int main(int argc, char** argv)
{
	if(argc <3 )
		return 1;
	char* file1 = argv[1];
	char* file2 = argv[2];
	sequence_table* table1;//thread , contents
	sequence_table* table2;//thread , contents

	SequenceAnalyzer sa;

	table1 = sa.divide_by_thread(file1);
	table2 = sa.divide_by_thread(file2);

	int cmd;
	while(true)
	{
		std::cout<<"1. print out to files by thread number"<<std::endl;
		std::cout<<"2. find out where the difference between two contents occurs "<<std::endl;
		std::cout<<"Enter cmd :  ";
		scanf("%d",&cmd);
		switch(cmd)
		{
			case 1:
				sa.print_sequence_table_into_file(*table1, argv[1]);
				sa.print_sequence_table_into_file(*table2, argv[2]);
				break;
			case 2:
				int thr1, thr2;
				std::cout<<"type thread number from "<<argv[1];
				scanf("%d",&thr1);
				std::cout<<"type thread number from "<<argv[2];
				scanf("%d",&thr2);
				sa.compare((*table1)[thr1],(*table2)[thr2]);
				break;
			default:
				std::cout<<"invalid command "<<std::endl;
				
		}
	}


	return 0;
}

