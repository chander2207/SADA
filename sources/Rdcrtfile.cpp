#include "Rdcrtfile.h"
#include "Utilityfunc.h"

bool Rdcrtfile::file_exist(const std::string& name) {
	std::ifstream file(name.c_str());
        return file.good();
}

int Rdcrtfile::create_file(const std::string& line, const int& id, std::string& file_name){
        file_name = "File-"+std::to_string(id);

	std::fstream file(file_name,std::ios::out);
        if(!file)
        {
                return 0;
        }
        //std::cout <<"File created successfully" << endl;
        /* Write value to the file */
        file << line;

        /* Close the file */
        file.close();
        return 1;
}

int Rdcrtfile::create_companion_file(const int& content, const int& id, std::string& hash_file_name){
        hash_file_name = "File-"+std::to_string(id)+".hash";

	std::fstream file(hash_file_name,std::ios::out);
        if(!file)
        {
                return 0;
        }
        //std::cout <<"File created successfully" << endl;

        /* Write value to the file */
        file << content;

        /* Close the file */
        file.close();
        return 1;
}

int Rdcrtfile::get_file_size(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

int Rdcrtfile::read_create_file(const std::string& infile, std::vector<std::pair<int, std::string>>& file_sz, std::vector<std::pair<std::string, int>>& duplicate_file){
	Utilityfunc u_func;
	std::string line, file_name, hash_file_name;
        int total_non_blank_line = 0;

	std::unordered_map<int, std::string> file_hash_dedup;
        /* Open the file to read. */
	std::ifstream file(infile);

        /* string variable to read the file line by line */
        while(getline(file, line)){
                if(!line.empty()){
                        total_non_blank_line++;
                        //std::cout << line <<endl<<endl;
                        int status = create_file(line, total_non_blank_line, file_name);
                        if(status == 0){
				std::cout<<"Error in creating file!!!";
                                return -1;
                        }
                        //std::cout <<"file_name: " << file_name << endl;

                        /* Create the hash digest for each line */
                        int hash_digest = u_func.hash_line(line);

                        /* Check for the duplicacy of hash content */
                        if(file_hash_dedup.find(hash_digest) != file_hash_dedup.end()){
                                duplicate_file.push_back(std::make_pair(file_hash_dedup[hash_digest],hash_digest));
                                duplicate_file.push_back(std::make_pair(file_name,hash_digest));
                        }else{
                                file_hash_dedup[hash_digest] = file_name;
                        }

                        /* fetch the size of file */
                        int f_sz = get_file_size(file_name);
                        if(f_sz == -1){
                                return -1;
                        }

                        /* Make pair for the vector based on file size */
                        file_sz.push_back(std::make_pair(f_sz,file_name));

                        /* Creating the companion file */
                        status = create_companion_file(hash_digest, total_non_blank_line, hash_file_name);
                        if(status == 0){
				std::cout<<"Error in creating file!!!";
                                return -1;
                        }
                        //std::cout <<"file_name hash: " << hash_file_name << endl;
                }
        }
        return total_non_blank_line;
}

