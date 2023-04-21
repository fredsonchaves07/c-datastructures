SRC = ./src
BIN = ./bin
INCLUDE = ./include
MODULES = ./modules
OBJ = ./obj
APP = ./apps
LIB = ./lib
DATASTRUCTURE_DIR = ./src/datastructures
TEST_DIR = ./test
TMP = ./tmp

FLAGS = -O3 -Wall
LIBS = -lm -led -L $(LIB)

all: directory libed myapps

test: directory libed mytest run_test

libed: \
	$(OBJ)/linked_list.o \
	$(OBJ)/doubly_linked_list.o \
	$(OBJ)/array_list.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: clean_apps \
	$(BIN)/perfomance_datastructures.x

mytest: clean_apps \
	$(BIN)/test_app.x

clean_apps:
	rm -rf $(BIN)/*

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/* $(TMP)/*

directory:
	mkdir -p $(BIN) $(OBJ) $(LIB) $(TMP)

run:
	$(BIN)/app.x

run_test:
	$(BIN)/test_app.x

$(OBJ)/%.o: $(DATASTRUCTURE_DIR)/*/%.c $(INCLUDE)/*/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%.x: $(APP)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

$(BIN)/%.x: $(TEST_DIR)/test_app.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) $(MODULES)/Unity/unity.c -o $@
