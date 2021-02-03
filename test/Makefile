.PHONY: test

test: $(BUILD_DIR)/conversion_test  $(BUILD_DIR)/threshold_test $(BUILD_DIR)/sobel_test



$(OBJ_DIR)/conversion_test.o: $(TEST_DIR)/conversion_test.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(OBJ_DIR)/threshold_test.o: $(TEST_DIR)/threshold_test.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sobel_test.o: $(TEST_DIR)/sobel_test.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(BUILD_DIR)/conversion_test: $(OBJ_DIR)/conversion_test.o $(OBJ_DIR)/conversion.o $(OBJ_DIR)/pgm.o
	$(CC) $^ -o $@

$(BUILD_DIR)/threshold_test: $(OBJ_DIR)/threshold_test.o $(OBJ_DIR)/thresholding.o $(OBJ_DIR)/pgm.o
	$(CC) $^ -o $@

$(BUILD_DIR)/sobel_test: $(OBJ_DIR)/sobel_test.o $(OBJ_DIR)/sobel.o $(OBJ_DIR)/pgm.o
	$(CC) $^ -o $@
