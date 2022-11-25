SRC = ./src
BIN = ./bin
INCLUDE = ./include
MODULES = ./modules
OUT = ./out
APP = app.c
BINAPP = app.x

all: library run

library: \
	app.x

myapps:
	echo "Defined app"

%.x: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $< -I $(INCLUDE) ${MODULES}/Unity/unity.c -o $(BIN)/$@

run:
	${BIN}/${BINAPP}

clean:
	rm -rf ${BIN}/*