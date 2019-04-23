CC=gcc
CFLAGS=-I
BIN_DIR=bin/
LIB_DIR=lib/
OBJ_DIR=obj/
MIDTERM_DIR=Midterm_Review/
FINAL_DIR=Final_Review/
EXERCISES=basic_arrays advanced_arrays bitwise operational_expression remove_lines sub_it

all: $(EXERCISES)

advanced_arrays:
	$(CC) -o $(BIN_DIR)/advanced_arrays advanced_arrays.c $(CFLAGS)

basic_arrays:
	$(CC) -o $(BIN_DIR)/basic_arrays1 basic_arrays.c $(CFLAGS)
	$(CC) -o $(BIN_DIR)/basic_arrays2 basic_arrays2.c $(CFLAGS)
	$(CC) -o $(BIN_DIR)/basic_arrays3 basic_arrays3.c $(CFLAGS)
	$(CC) -o $(BIN_DIR)/basic_arrays4 basic_arrays4.c $(CFLAGS)
	$(CC) -o $(BIN_DIR)/basic_arrays5 basic_arrays5.c $(CFLAGS)

bitwise:
	$(CC) -o $(BIN_DIR)/bitwise bitwise.c $(CFLAGS)

midterm.o: $(MIDTERM_DIR)/EnglishFunctions.h
	$(CC) -c -o $(OBJ_DIR)/EnglishFunctions.o $(MIDTERM_DIR)/EnglishFunctions.c $(CFLAGS)
	$(CC) -c -o $(OBJ_DIR)/UnitTestCode.o $(MIDTERM_DIR)/UnitTestCodev2.c $(CFLAGS)

midterm: midterm.o
	$(CC) -o $(BIN_DIR)/midterm $(OBJ_DIR)/EnglishFunctions.o $(OBJ_DIR)/UnitTestCode.o $(CFLAGS)

operational_expression:
	$(CC) -o $(BIN_DIR)/operational_expression operational_expression.c $(CFLAGS)

remove_lines:
	$(CC) -o $(BIN_DIR)/remove_lines remove_lines.c $(CFLAGS)

sub_it:
	$(CC) -o $(BIN_DIR)/sub_it sub_it.c $(CFLAGS)

clean:
	rm -f $(BIN_DIR)/*