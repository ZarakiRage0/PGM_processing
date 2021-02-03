/**
 * @file conversion.c
 * @author RGUIG Reda
 * This file contains the definitions of functions used for converting
 * images(bin/asci).
 */
#include <conversion.h>

void convert_pgm(char* input, char* output){
	int a;
	PgmImg* img;

	a = is_binary(input);

	if ( a==0 ) {
		img = malloc(sizeof(PgmImg));
		read_pgm_img_BIN(input,img);
		strcpy(img->magic_number,"P2");
		write_pgm_img_ASCII(output,img);
		free_pgm(img);
	} else if ( a==1 ){
		img = malloc(sizeof(PgmImg));
		read_pgm_img_ASCII(input,img);
		strcpy(img->magic_number,"P5");
		write_pgm_img_BIN(output,img);
		free_pgm(img);
	} else {
		fprintf(stderr,"Conversion failed");
	}

}
