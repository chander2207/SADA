#include "Utilityfunc.h"
#include "Rdcrtfile.h"

void Utilityfunc::list_files(const std::vector<std::pair<int,std::string>>& file_list){
	std::cout <<"Display the list of file based on its size: " <<std::endl;
        for(const auto& vec: file_list){
		std::cout << vec.second << "\t\t"<<vec.first << std::endl;
        }
	std::cout<<std::endl;
}

void Utilityfunc::list_dup_file(const std::vector<std::pair<std::string, int>>& dup_list){
	std::cout <<"Duplicate files are: " <<std::endl;
        for(unsigned int i=0; i < dup_list.size()-1; i+=2){
		std::cout << dup_list[i].first <<" and " << dup_list[i+1].first <<std::endl;
		std::ifstream file(dup_list[i].first);
                if(!file){ exit(0);}
		std::string line;
                getline(file,line);
		std::cout << "File content: "<<std::endl<<line <<std::endl;
        }
	std::cout<<std::endl;
}

unsigned Utilityfunc::hash_line(const std::string& line)
{
        unsigned h = FIRSTH;
        for(const char& ch: line) {
                h = (h * A) ^ (ch * B);
        }
        return h % C;
}

void Utilityfunc::usage(const std::string& name){
	std::cout <<"Usage:" <<std::endl <<"\t" << name << " <file_name>" << std::endl
        <<"\tProgram takes only one input which is file name." << std::endl;
}

