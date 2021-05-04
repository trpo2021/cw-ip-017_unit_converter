
BIN = bin/
OBJ_MAIN = obj/src/converter/
OBJ_LIBS = obj/src/libconverter/
SRC_MAIN = src/converter/
SRC_LIB = src/libconverter/

PROJECT_NAME = Unit_converter

MAIN_FILE = main

CFLAGS =-Wall -Wextra -Werror


CPPFLAGS =-Isrc -Iconverter -MP -MMD 

GPP = g++
PACKAGE = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

PROJECT_LANG = .cpp
EXE = .exe

.PHONY: all

all: $(BIN)$(PROJECT_NAME)$(EXE)

$(BIN)$(PROJECT_NAME)$(EXE): $(OBJ_MAIN)$(MAIN_FILE).o 
	$(GPP) $(CFLAGS) $(CPPFLAGS) $(OBJ_MAIN)$(MAIN_FILE).o -o $(BIN)$(PROJECT_NAME)$(EXE) $(LIBS)

$(OBJ_MAIN)$(MAIN_FILE).o: $(SRC_MAIN)$(MAIN_FILE)$(PROJECT_LANG)
	$(GPP) $(CFLAGS) $(CPPFLAGS) -c $(SRC_MAIN)$(MAIN_FILE)$(PROJECT_LANG) -o $(OBJ_MAIN)$(MAIN_FILE).o $(PACKAGE)
	
.PHONY: clean

clean:
	find $(OBJ_MAIN) -name "*.o" -type f -delete
	find $(OBJ_MAIN) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.o" -type f -delete
	find $(OBJ_LIB) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.a" -type f -delete