CC = gcc
FLAGS = -I include

SRC_DIR = src
TEST_DIR = test
INC_DIR = include
BUILD_DIR = build

VPATH = $(SRC_DIR) $(TEST_DIR) $(INC_DIR)

train: train.c
	$(CC) $(FLAGS) -o $(BUILD_DIR)/train $(SRC_DIR)/train.c -lm

unit_math: unit_math.c nn_math.c c_unit_implementation.c
	$(CC) $(FLAGS) -o $(BUILD_DIR)/unit_math $(TEST_DIR)/unit_math.c $(INC_DIR)/nn_math.c $(TEST_DIR)/c_unit_implementation.c -lm
