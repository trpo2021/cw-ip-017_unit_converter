
BIN = bin/
OBJ_MAIN = obj/src/converter/
OBJ_LIBS = obj/src/libconverter/
SRC_MAIN = src/converter/
SRC_LIB = src/libconverter/
APP_PATH_TEST = bin/test.exe

PROJECT_NAME = Unit_converter
LIB_FILE = converter
MAIN_FILE = main

CFLAGS =-Wall -Wextra -Werror


CPPFLAGS =-Isrc -Iconverter -MP -MMD  -Ithirdparty

GPP = g++
PACKAGE = $(shell pkg-config --cflags gtk+-3.0)
LIBS = $(shell pkg-config --libs gtk+-3.0)



PROJECT_LANG = .cpp
EXE = .exe

.PHONY: all

all: $(BIN)$(PROJECT_NAME)$(EXE)

$(BIN)$(PROJECT_NAME)$(EXE): $(OBJ_MAIN)$(MAIN_FILE).o  $(OBJ_LIBS)$(LIB_FILE).o
	$(GPP) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LIBS)

$(OBJ_MAIN)$(MAIN_FILE).o: $(SRC_MAIN)$(MAIN_FILE)$(PROJECT_LANG)
	$(GPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ $(PACKAGE)
	
$(OBJ_LIBS)$(LIB_FILE).o: $(SRC_LIB)$(LIB_FILE).cpp
	$(GPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ $(PACKAGE)


.PHONY: test
test: $(APP_PATH_TEST)

$(APP_PATH_TEST): obj/test/test.o obj/test/main.o obj/src/libconverter/converter.o
	$(GPP) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LIBS)  
obj/test/test.o: test/test.cpp
	$(GPP) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(PACKAGE)
obj/test/main.o: test/main.cpp
	$(GPP) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(PACKAGE)


.PHONY: clean
OBJ_TEST = obj/test/
clean:
	find $(OBJ_MAIN) -name "*.o" -type f -delete
	find $(OBJ_MAIN) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.o" -type f -delete
	find $(OBJ_LIB) -name "*.d" -type f -delete
	find $(OBJ_LIB) -name "*.a" -type f -delete
	find $(OBJ_TEST) -name "*.o" -type f -delete
	find $(OBJ_TEST) -name "*.d" -type f -delete
	find $(OBJ_TEST) -name "*.a" -type f -delete
