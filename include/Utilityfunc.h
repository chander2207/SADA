#ifndef _UTILITYFUNC_H_
#define _UTILITYFUNC_H_

#include "Rdcrtfile.h"


/* Below are the values used while calculating the hash digest */
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */

class Utilityfunc{
	public:
		/* This function used to create the hash digest for each file. */
		unsigned hash_line(const std::string& line);

		/* It defines the utility of the running code. */
		void usage(const std::string& name);

		/* It will help to display all the files with its size in ascending order. */
		void list_files(const std::vector<std::pair<int,std::string>>& file_list);

		/* It will display the duplicate files on the screen along with its content */
		void list_dup_file(const std::vector<std::pair<std::string, int>>& dup_list);
};

#endif
