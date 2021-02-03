.PHONY: all clean distclean
CC = gcc
CPPFLAGS = -I./include
CFLAGS = -Wall -Wextra

OBJ_DIR = ./bin/misc
BUILD_DIR = ./bin/build
PGM_DIR = ./src/PGM
SRC_DIR = ./src
TEST_DIR = ./test
IMG_DIR = ./etc


all : $(BUILD_DIR)/threshold $(BUILD_DIR)/sobel

$(BUILD_DIR)/threshold: $(OBJ_DIR)/images.o $(OBJ_DIR)/threshold_main.o $(OBJ_DIR)/thresholding.o
	$(CC) $^ -o $@

$(BUILD_DIR)/sobel:  $(OBJ_DIR)/images.o $(OBJ_DIR)/sobel_main.o $(OBJ_DIR)/sobel.o
	$(CC) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(IMG_DIR)/*.pgm

distclean:
	make clean
	rm -rf $(BUILD_DIR)/*

include ./src/Makefile
include ./test/Makefile
