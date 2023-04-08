Group Members: Kyndra Nelson, Mallorie Mackay, Ian Hunt, Kalyan Adhikari, Ryan Cocks

To compile the program on the UNT CELL machines, one can run the following:

g++ *.cpp *.h

Then, to run the program, type the following:

./a.out

When prompted to type the name of the config file, the config file must reside
within the same directory as the main.cpp file. This also applies to the
region file defined in the config file. Also, the region file name that is
defined in the config file must be the full path, such as below:

/nfs/home/STUDENTS/INSERT_EUID_HERE/csce2110/Project1/region.csv

Notes: The bonus was not implemented. Further, in our gitlab, the master branch is 
an organized version of the code (by having different directories). The files on the
branch "cell-machines" are what were submitted, as there were some small changes
to the include statements to match what was wanted on the CELL machines.
