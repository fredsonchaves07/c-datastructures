SRC = ./src
BIN = ./bin
INCLUDE = ./include
MODULES = ./modules
OBJ = ./obj
APP = ./apps
LIB = ./lib
DATASTRUCTURE_DIR = ./src/datastructures
TEST_DIR = ./test

FLAGS = -o3 -Wall
LIBS = -lm -ldatastructurec -L $(LIB)

all: library myapps

$(OBJ)/%.o: $(SRC)/algorithms/examples/tad/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%.x: $(APP)/tad/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

library: \
	$(OBJ)/*.o
	ar -rcs $(LIB)/libdatastructurec.a $(OBJ)/*.o

myapps: clean_apps \
	$(BIN)/app.x

clean_apps:
	rm -rf $(BIN)/*

run:
	$(BIN)/app.x

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*