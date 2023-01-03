SRC = ./src
BIN = ./bin
INCLUDE = ./include
MODULES = ./modules
OBJ = ./obj
APP = ./apps
LIB = ./lib

FLAGS = -o3 -Wall
LIBS = -lm -ldatastructurec -L $(LIB)

all: library myapps

library: \
	$(OBJ)/*.o
	ar -rcs $(LIB)/libdatastructurec.a $(OBJ)/*.o

myapps: clean_apps \
	$(BIN)/app.x

$(OBJ)/%.o: $(SRC)/algorithms/examples/tad/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)/app.x

$(BIN)/%.x: $(APP)/tad/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(LIB)/*

clean_apps:
	rm -rf $(BIN)/*