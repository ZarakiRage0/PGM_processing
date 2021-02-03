/**
 * @file pgm.c
 * @author RGUIG Reda
 * This file contains the definitions of functions used for handling pgm.
 */

#include <pgm.h>

int is_pgm(char *file_name){
	FILE* file;
	char version[3];
	int is_gray;

	is_gray = 1;

	file = fopen(file_name, "rb");
	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	fgets(version,sizeof(version), file);

	if ( strcmp(version,"P2") == 0 ){
		is_gray = 0;
	}
	if ( strcmp(version,"P5") == 0 ){
		is_gray = 0;
	}

	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	return is_gray;
}

int is_binary(char *file_name){
	FILE* file;
	char version[3];
	int is_bin;

	is_bin = 2;

	file = fopen(file_name, "rb");
	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	fgets(version,sizeof(version), file);

	if ( strcmp(version,"P2") == 0 ){
		is_bin = 1;
	}
	if ( strcmp(version,"P5") == 0 ){
		is_bin = 0;
	}

	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}
	if ( is_bin == 2 ){
		return EXIT_FAILURE;
	}
	return is_bin;

}

void skip(FILE* fp){
	char ch;

	//check for white space
	while ((ch = fgetc(fp)) != EOF && isspace(ch)) {
		;
	}

	//check for comments
	while (ch == '#') {
		while (getc(fp) != '\n') ;
		ch = getc(fp);
		}
	//push back the char into the stream.
	ungetc(ch, fp);

}

int read_pgm_img_ASCII(char* file_name, PgmImg* image){
	FILE* file;
	unsigned char pixel;
	int i;
	int j;
	//Opening file
	file = fopen(file_name, "r");

	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	//Reading the header
	fgets(image->magic_number,sizeof(image->magic_number),file);
	skip(file);
	fscanf(file,"%d",&image->width);
	skip(file);
	fscanf(file,"%d",&image->height);
	skip(file);
	fscanf(file,"%hhd",&image->color_max);
	//skip(file);
	while (fgetc(file) != '\n') ;

	//memory allocation to data
	image->data = malloc(sizeof(unsigned char)*image->width*image->height);
	if ( image->data == NULL ) {
		fprintf(stderr, "Unable to allocate memory\n");
		return EXIT_FAILURE;
	}

	//storing data
	for (i=0;i<image->height;i++) {
		for (j=0;j<image->width;j++) {
			if (fscanf ( file, "%hhd" ,&pixel ) !=1){
				printf(" in : %d %d", i,j);
				printf ( "  Unable to read data.\n" );
				return EXIT_FAILURE;
			}
			image->data[i*image->width + j]= pixel;
		}
	}


	//closing file
	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}
	return 0;
}

int read_pgm_img_BIN(char* file_name, PgmImg* image){
	FILE* file;
	char pixel;
	int i;
	int j;
	//Opening file
	file = fopen(file_name, "rb");

	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}
	//Reading the header
	fgets(image->magic_number,sizeof(image->magic_number),file);
	skip(file);
	fscanf(file,"%d",&image->width);
	skip(file);
	fscanf(file,"%d",&image->height);
	skip(file);
	fscanf(file,"%hhd",&image->color_max);
	while (fgetc(file) != '\n') ;

	//memory allocation to data
	image->data = malloc(sizeof(unsigned char)*image->width*image->height);
	if ( image->data == NULL ) {
		fprintf(stderr, "Unable to allocate memory\n");
		return EXIT_FAILURE;
	}

	//storing data
	for (i=0;i<image->height;i++) {
		for (j=0;j<image->width;j++) {
			pixel = fgetc(file);
			if ( pixel == EOF ) {
				printf(" in : %d %d", i,j);
				fprintf ( stderr, "  Unable to read data.\n" );
				return EXIT_FAILURE;
			}
			image->data[i*image->width + j]= (unsigned char)pixel;
		}
	}


	//closing file
	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}
	return 0;
}

int write_pgm_img_ASCII(char* file_name, PgmImg* image){
	FILE* file;
	int i;
	int j;
	//Opening file
	file = fopen(file_name, "w");

	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	//writing header
	fprintf(file, "%s\n",image->magic_number);
	fprintf(file, "%d %d\n",image->width,image->height);
	fprintf(file, "%u\n",image->color_max);

	//writing data
	for (i=0;i<image->height;i++) {
		for (j=0;j<image->width;j++) {
			fprintf(file," %u",image->data[i*image->width +j]);
		}
		fprintf(file,"\n");
	}



	//closing file
	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	return 0;
}

int write_pgm_img_BIN(char* file_name, PgmImg* image){
	FILE* file;
	int i;
	int j;
	unsigned char pixel;
	//Opening file
	file = fopen(file_name, "wb");

	if ( file == NULL ) {
		fprintf(stderr," Error while opening the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	//writing header
	fprintf(file, "%s\n",image->magic_number);
	fprintf(file, "%d %d\n",image->width,image->height);
	fprintf(file, "%u\n",image->color_max);

	//writing data
	for (i=0;i<image->height;i++) {
		for (j=0;j<image->width;j++) {
			pixel = image->data[i*image->width+j];
			fputc(pixel,file);
		}
	}



	//closing file
	if (fclose(file) == EOF){
		fprintf(stderr," Error while closing the file %s.\n ", file_name);
		return EXIT_FAILURE;
	}

	return 0;
}

void free_pgm(PgmImg* img){
	free(img->data);
	free(img);
}
