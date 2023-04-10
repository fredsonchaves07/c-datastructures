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

FLAGS = -o3 -Wall
LIBS = -lm -ldatastructurec -L $(LIB)

all: library myapps

$(OBJ)/%.o: $(SRC)/datastructures/list/%.c $(INCLUDE)/list/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $(OBJ)/libdatastructurec.o

$(BIN)/%.x: $(APP)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

$(BIN)/%.x: $(TEST_DIR)/test_app.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) $(MODULES)/Unity/unity.c -o $@


library: \
	$(OBJ)/*.o
	ar -rcs $(LIB)/libdatastructurec.a $(OBJ)/libdatastructurec.o

myapps: clean_apps \
	$(BIN)/perfomance_datastructures.x

mytest: clean_apps \
	$(BIN)/test_app.x

clean_apps:
	rm -rf $(BIN)/*

run:
	$(BIN)/app.x

test: clean_apps library mytest run_test

run_test:
	$(BIN)/test_app.x

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/* $(TMP)/*