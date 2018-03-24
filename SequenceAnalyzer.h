#ifndef SEQUENCE_ANALYZER_H_
#define SEQUENCE_ANALYZER_H_

#include <vector>
#include <map>
#include <string>

enum {
	MAXBUFFER= 8192
}	;

struct contents
{
	int pos;//line number where the contents exist
	std::string body;
};

typedef std::vector<struct contents> sequence;
typedef std::map<int, sequence > sequence_table;
/*
 * Analyzing format 
 * thread_number	key(some parameters) any other things
 * ex)
 *	1				fopen("myfile.txt","rt") somebodyhelpme
 *
 *
 **
 */
class SequenceAnalyzer
{
private:
	std::string del;


public:
	SequenceAnalyzer() : del(" \t") {}
	inline void setdelimeter(const char* delimeter)
	{
		del  = delimeter;
	}
	sequence_table* divide_by_thread(const char* filename);
	void print_sequence_table_into_file(sequence_table& table, const char* prefix_filename );
	void compare(const sequence& s1, const sequence& s2);



};




#endif
