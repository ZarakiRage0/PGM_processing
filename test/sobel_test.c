/**
 * @file sobel_test.c
 * @author RGUIG Reda
 * This file contains some test  for sobel (image processing).
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgm.h>



char *test_file_1 = "./images/boats_small.pgm";
char *test_file_2 = "./images/barbara.pgm";
char *test_file_3 = "./images/lena.pgm";
char *test_file_4 = "./images/PengBrew.pgm";


char* sobel_boat_bin_pgm = "./etc/sobel_boat_bin.pgm";
char* sobel_barbara_pgm = "./etc/sobel_barbara.pgm";
char* sobel_lena_pgm = "./etc/sobel_lena.pgm";
char* sobel_PengBrew_pgm = "./etc/sobel_PengBrew.pgm";

void test_sobelold(){
	printf("\n\t\t Test sobel \n");
	sobel_pgm(test_file_1,sobel_boat_bin_pgm);
  sobel_pgm(test_file_2,sobel_barbara_pgm);
  sobel_pgm(test_file_3,sobel_lena_pgm);
  sobel_pgm(test_file_4,sobel_PengBrew_pgm);
	printf("\n\t\t Done \n");
}

int main(){
	test_sobelold();
	return 0;
}
