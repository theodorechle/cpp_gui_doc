CC=g++
CFLAGS=-std=c++17 -Wall -g -MMD -MP
SDL_CMD=`pkg-config sdl3 sdl3-ttf --cflags --libs`
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
LIB=cpp_gui/bin/cpp_gui_lib
MAIN=bin/cpp_gui_doc

SRC_MAIN=$(SRC_DIR)/main.cpp

# Subdirectories
PAGES=pages
SUBDIRS=pages pages/manager app_utils
SRC_SUBDIRS=$(foreach dir, $(PAGES)/*, $(wildcard $(SRC_DIR)/$(dir)/*.cpp)) $(foreach dir, $(SUBDIRS), $(wildcard $(SRC_DIR)/$(dir)/*.cpp))
OBJ_SUBDIRS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_SUBDIRS))

.PHONY: all clean

all: $(MAIN)

$(MAIN): $(OBJ_SUBDIRS) $(SRC_MAIN) $(LIB).a
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ $(SDL_CMD) -o $@

$(LIB).a:
	$(MAKE) -C cpp_gui -j lib

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean all generated files
clean:
	@find obj -mindepth 1 ! -name .gitkeep -delete
	@find bin -mindepth 1 ! -name .gitkeep -delete
	$(MAKE) -C cpp_gui clean