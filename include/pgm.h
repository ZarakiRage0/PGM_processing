/**
 * @file pgm.h
 * @author RGUIG Reda
 * This file contains the prototype of functions used for handling PGM images.
 * These functions are used to read/write images from/into a file.
 * Some are used to determine the type of the image.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef PMG_H
#define PMG_H


/**
  *@brief Struct of a PGM IMG.
  */
struct PGMIMG{
	char magic_number[3];
	int width;
	int height;
	unsigned char color_max;
	unsigned char *data;
};
typedef struct PGMIMG PgmImg;


/**
  *@brief checks if the file is a PGM or not.
  *
  *@return 0 if it's pgm, else 1.
  */
int is_pgm(char*);


/**
  *@brief checks if the PGM file is in binary or not.
  *
  *@return 0 if it's binary, 1 if it's in ASCII, else EXIT_FAILURE.
  */
int is_binary(char*);


/**
  *@brief skips white spaces in PGM file.
  */
void skip(FILE*);


/**
  *@brief stores an ASCII format PGM IMG file in a struct.
  */
int read_pgm_img_ASCII(char*, PgmImg*);


/**
  *@brief stores an BIN format PGM IMG file in a struct.
  */
int read_pgm_img_BIN(char*, PgmImg*);


/**
  *@brief writes a Pgm Img struc in file using ASCII format.
  */
int write_pgm_img_ASCII(char*, PgmImg*);


/**
  *@brief writes a Pgm Img struc in file using BIN format.
  */
int write_pgm_img_BIN(char*, PgmImg*);


/**
  *@brief frees a PgmImg struct.
  */
void free_pgm(PgmImg*);


#endif
