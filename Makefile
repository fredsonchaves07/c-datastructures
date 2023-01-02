SRC = ./src
BIN = ./bin
INCLUDE = ./include
MODULES = ./modules
OBJ = ./obj
APP = ./apps

all: library myapps run clean

library: \
	float_vector.o

myapps:
	gcc $(APP)/tad/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app.x

%.o: $(SRC)/algorithms/examples/tad/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $(OBJ)/$@

run:
	$(BIN)/app.x

clean:
	rm -rf $(BIN)/* $(OBJ)/*