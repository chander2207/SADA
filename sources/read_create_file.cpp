#include "Rdcrtfile.h"
#include "Utilityfunc.h"

using namespace std;

int main(int argc, char* argv[]){
	Rdcrtfile rc_file;	
	Utilityfunc u_func;

	/* This program only takes the 2 inputs. */
	if(argc != 2){
		u_func.usage(argv[0]);
		return 0;
	}

	cout << "The input string is: " << argv[1] <<endl;
	
	/* Check if the input file exist or not */
	if(!rc_file.file_exist(argv[1])){
		cout << "File name does not exist. Check file name again" << endl;
		return 0;
	}
	
	

	/* vector to hold the value of file size and file hash */
	vector<pair<int,string>> file_size_list; 
	vector<pair<string, int>> duplicate_file_list; 
	
	int status = rc_file.read_create_file(argv[1], file_size_list, duplicate_file_list);
	if(status == -1){
		exit(0);
	}

	cout << "Total number of non blank line: " << status << endl << endl;

	/* Sort the file based on the file size in ascending order */
	sort(file_size_list.begin(),file_size_list.end());

	/* display the file based on the size */
	u_func.list_files(file_size_list);

	/* display the duplicate file and content */
	u_func.list_dup_file(duplicate_file_list);
	
	cout<<"Removing the duplicate line using the awk command" << endl << endl;
	system("awk '!NF || !seen[$0]++' ../data/loomings.txt > ../data/loomings-clean.txt");
	
	cout <<"Showing the difference between 2 files using diff command"<<endl<<endl;
	system("diff ../data/loomings.txt ../data/loomings-clean.txt");
	return 0;
}
