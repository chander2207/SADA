## What this project does

This project reads the file and one by one creates the file for every non-blank line read.
Once it reads the line, 
	-- it calcualte the hash digest for the line.
	-- it create the file to contain the line.
	-- it creates the companion file which contains the hash digest calcualted earlier.

It checks for the duplicate file and display those file on the stdout.
After this, it will create a file "loomings-clean.txt" which will contain unique lines and
thereafter produces the difference between the two files "loomings.txt" and "loomings-clean.txt"

## To install
Make sure to dowload and move the "SADA" folder at the HOME Dir.
Otherwise run.sh would not work.

## To run the project
You can run this project in two ways:
	-- simply run "run.sh" and it would do all the necessary job.
	-- You can follow steps mentioned in the "build" folder README.md

## To test
This project uses the input from the file which is placed in the data folder
If the file is removed then project should crash.


## Future Enhancement
Instead of using the system command in the main to execute the awk command and the diff 
command, they can be done explicitly in C++ which will take some time to implement.
