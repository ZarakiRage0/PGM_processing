My Main Page                         {#mainpage}
============


# PGM_processing
 Contains source code to handle PGM files and apply some processing on them.

## About the Project
  This sort of mini project focuses on PGM files.
  It contains functions for:
- reading/writing from/into PGM files.
- converting these files from/to bin/ASCII.
- applying the threshold method.
- applying the sobel method. (only in one direction)
  Some other image processing methods may be added in the future.

## Contents of the folder

- ./src *( contains source code  )*
- ./test/
- ./include *( Header files )*
- ./doc *( Documentation )*
	- Doxygen *( file to generate html documentations )*
- bin/
    - ./misc/ *( folder for the object files )*
    - ./build/ *( folder for the executables )*
- ./images *(Some PGM samples)*
- ./etc *( folder for the PGM files generated from tests)*
- README.md
- Makefile

## How to use the makefile

To generate the executable :

- main :

		make  
or

   	make all

- test : 	


    	make test

to clean the directory from :

- obj files / PGM files :

  	make clean

- obj files/ PGM files /Executables :

  	make distclean


## Running the different mains



## How to generate Documentation

  		doxygen ./doc/Doxyfile
