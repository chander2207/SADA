#ifndef _RDCRTFILE_H_ 
#define _RDCRTFILE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class Rdcrtfile{
	public:
		/* This function reads the input file and then create files corresponding to the non-blank lines */
		int read_create_file(const std::string& infile, std::vector<std::pair<int, std::string>>& file_sz, std::vector<std::pair<std::string, int>>& duplicate_file);
		
		/* This function checks whether file exist or not. */
		bool file_exist(const std::string& name);
	private:
		/* It helps the read_create_file function to create file */
		int create_file(const std::string& line, const int& id, std::string& file_name);
		
		/* It helps the read_create_file function to create companion file containing the hash digest. */
		int create_companion_file(const int& content, const int& id, std::string& hash_file_name);

		/* This function is used to get the size of the file. */
		int get_file_size(std::string filename);
};

#endif
