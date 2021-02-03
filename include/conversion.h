/**
 * @file conversion.h
 * @author RGUIG Reda
 * This file contains the prototype of functions used for converting PGM images
 * (bin/ascii).
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pgm.h>
#include <ctype.h>

#ifndef CONVERT_H
#define CONVERT_H

/**
  *@brief convert a pgm img from ASCI to BIN or vice versa.
  */
void convert_pgm(char* input, char* output);

#endif
