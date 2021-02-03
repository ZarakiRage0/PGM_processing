
/**
 * @file thresholding.h
 * @author RGUIG Reda
 * This file contains the prototypes of functions used for thresholding (PGM image
 * processing).
 */
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <pgm.h>
 #include <ctype.h>

#ifndef TRH_H
#define TRH_H

/**
  *@brief Using the treshold method to process a Pgm img.
  */
void thresholding_pgm(char* input,char* output, unsigned char threshold);

#endif
