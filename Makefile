CPP_C=g++
CPP_FLAGS=-std=c++17 -Wall -g -MMD -MP
SDL_CMD=`pkg-config sdl3 sdl3-ttf --cflags --libs`
BIN_DIR=bin
OBJ_DIR=obj
SRC_DIR=src
GUI_LIB=cpp_gui/bin/cpp_gui_lib
STYLE_LIB=cpp_gui/cpp_style/bin/cpp_style_lib
MAIN=bin/cpp_gui_doc

SRC_MAIN=$(SRC_DIR)/main.cpp

# Subdirectories
SUBDIRS=pages pages/manager app_utils
SRC_SUBDIRS=$(foreach dir, pages/*, $(wildcard $(SRC_DIR)/$(dir)/*.cpp)) $(foreach dir, pages/elements/*, $(wildcard $(SRC_DIR)/$(dir)/*.cpp)) $(foreach dir, $(SUBDIRS), $(wildcard $(SRC_DIR)/$(dir)/*.cpp))
OBJ_SUBDIRS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_SUBDIRS))

.PHONY: all clean

ifeq ($(DEBUG),1)
CPP_FLAGS += -DDEBUG
endif

all: $(MAIN)

$(MAIN): $(OBJ_SUBDIRS) $(SRC_MAIN) $(GUI_LIB).a $(STYLE_LIB).a # TODO: find a way to don't add all libraries by hand
	@mkdir -p $(BIN_DIR)
	$(CPP_C) $(CPP_FLAGS) $^ $(SDL_CMD) -o $@

$(GUI_LIB).a:
	$(MAKE) -C cpp_gui -j lib

$(STYLE_LIB).a:
	$(MAKE) -C cpp_gui/cpp_style -j lib

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPP_C) $(CPP_FLAGS) -c $< -o $@

# Clean all generated files
clean:
	@find obj -mindepth 1 ! -name .gitkeep -delete
	@find bin -mindepth 1 ! -name .gitkeep -delete
	$(MAKE) -C cpp_gui clean