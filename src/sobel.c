/**
 * @file sobel.c
 * @author RGUIG Reda
 * This file contains the definitions of functions used for sobel method (image
 * processing).
 */

#include <sobel.h>

void sobel_pgm(char* input,char* output){
  int bin;
	int gray;
	PgmImg* input_img;
  PgmImg* output_img;
  int i;
  int j;

  //Reading the input image

  bin = is_binary(input);

	gray = is_pgm(input);

	if ( gray != 0 ){
		fprintf(stderr," Invalid file \n");
		return;
	}

	input_img = malloc(sizeof(PgmImg));

	if ( bin == 0 ){
		read_pgm_img_BIN(input,input_img);
	} else {
		read_pgm_img_ASCII(input,input_img);
	}

  //Filling out the output image struct
  output_img = malloc(sizeof(PgmImg));
  strcpy(output_img->magic_number,input_img->magic_number);
  output_img->width = input_img->width ;
  output_img->height = input_img->height;
  output_img->color_max = input_img->color_max;
  //allocating the memory for the image's pixels and setting them to 0
  output_img->data = calloc(output_img->width*output_img->height, sizeof(unsigned char));

  //Applying the sobel methode for every pixel
  for (i = 1 ; i <(output_img->height - 1); i++) {
    for (j = 1 ; j <(output_img->width - 1); j++) {
      apply_sobel_on_pixel(input_img, output_img, i, j);
    }
  }

  //write the output img
  if ( bin == 0 ){
		write_pgm_img_BIN(output, output_img);
	} else {
		write_pgm_img_ASCII(output, output_img);
	}

  //free both imgs.
  free_pgm(input_img);
  free_pgm(output_img);
}

void apply_sobel_on_pixel(PgmImg* input, PgmImg* output,int row, int column){
  int i;
  int j;
  int pixel;
  pixel = 0;
  for ( i = -1; i <= 1; i++){
    for (j = -1; j <= 1; j++){
      pixel += sobel[i+1][j+1]* input->data[(row+i)*input->width + (column+j)];
    }
  }
  if (pixel < 0){
    pixel = 0 ;
  }else if (pixel > input->color_max){
    pixel = input->color_max;
  }
  output->data[row*output->width + column] = pixel;
}
