/**
 * @file conversion_test.c
 * @author RGUIG Reda
 * This file cointains some tests for the conversion of pgm.(ASCII & binary).
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgm.h>
#include <conversion.h>

char *test_file_1 = "./images/boats_small.pgm";
char *test_file_2 = "./images/boats_small_text.pgm";

char* bin2ascii_pgm = "./etc/bin2ascii_ppm.pgm";
char* ascii2bin_pgm = "./etc/ascii2bin_pgm.pgm";


void test_conversion(){
	printf("\n\t\t Test conversion \n");
	convert_pgm(test_file_1, bin2ascii_pgm);
	convert_pgm(test_file_2, ascii2bin_pgm);
	printf("\n\t\t Done \n");
}

int main(){
	test_conversion();
	return 0;
}
