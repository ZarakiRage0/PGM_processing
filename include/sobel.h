
/**
 * @file sobel.h
 * @author RGUIG Reda
 * This file contains the prototypes of functions used for sobel method (image
 * processing).
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgm.h>
#include <ctype.h>

#ifndef SBL_H
#define SBL_H

int sobel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; // sobel matrix
// int sobel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, -1}}; another direction for sobel

/**
  *@brief Apply the sobel filter on one pixel.
  */
void apply_sobel_on_pixel(PgmImg* input, PgmImg* output,int row, int column);

/**
  *@brief Using the sobel method to process a Pgm img.
  */
void sobel_pgm(char* input,char* output);

#endif
