/**
 * @file threshold_test.c
 * This file contains some test  for thresholding (image processing).
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgm.h>
#include <thresholding.h>

char *test_file_1 = "./images/boats_small.pgm";
char *test_file_2 = "./images/barbara.pgm";
char *test_file_3 = "./images/lena.pgm";
char *test_file_4 = "./images/PengBrew.pgm";

char* thresh_boat_bin_pgm = "./etc/thresh_boat_bin.pgm";
char* thresh_barbara_pgm = "./etc/thresh_barbara.pgm";
char* thresh_lena_pgm = "./etc/thresh_lena.pgm";
char* thresh_PengBrew_pgm = "./etc/thresh_PengBrew.pgm";



void test_threshold(){
  int coeff;
  coeff = 120;
	printf("\n\t\t Test threshold \n");
  thresholding_pgm(test_file_1,thresh_boat_bin_pgm,coeff);
  thresholding_pgm(test_file_2,thresh_barbara_pgm,coeff);
  thresholding_pgm(test_file_3,thresh_lena_pgm,coeff);
  thresholding_pgm(test_file_4,thresh_PengBrew_pgm,coeff);
	printf("\n\t\t Done \n");
}

int main(){
	test_threshold();
	return 0;
}
