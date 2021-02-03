/**
 * @file thresholding.c
 * @author RGUIG Reda
 * This file contains the definitions of functions used for thresholding (image
 * processing).
 */


#include <thresholding.h>

void thresholding_pgm(char* input,char* output, unsigned char threshold){
	int bin;
	int gray;
	int i;
	int j;
	PgmImg* img;
	unsigned char real_threshold;


	bin = is_binary(input);
	gray = is_pgm(input);

	if ( gray != 0 ){
		fprintf(stderr," Invalid file \n");
		return;
	}

	img = malloc(sizeof(PgmImg));

	if ( bin == 0 ){
		read_pgm_img_BIN(input,img);
	} else {
		read_pgm_img_ASCII(input,img);
	}

	real_threshold = (img->color_max > threshold) ?  threshold : img->color_max ;

	for (i=0;i<img->height;i++) {
		for (j=0;j<img->width;j++) {
			if (img->data[i*img->width + j] < real_threshold){
				img->data[i*img->width + j] = 0;
			}else {
				img->data[i*img->width + j] = img->color_max;
			}
		}
	}

	if ( bin == 0 ){
		write_pgm_img_BIN(output,img);
	} else {
		write_pgm_img_ASCII(output,img);
	}

	free_pgm(img);

}
