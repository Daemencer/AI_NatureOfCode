TARGET = ecosystem

SRC =	main.cpp\

BIN_DIR := ./bin/
OBJ_DIR := ./obj/
SRC_DIR := ./src/
INC_DIR := ./include/

SYS_LIBS := sfml-graphics sfml-window sfml-audio sfml-system GL
DEP_DIR :=
DEP_LIBS :=
DEP_MAKE :=

OBJ := $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC))
DEPENDENCIES := $(OBJ:.o=.d)
ARBO := $(sort $(dir $(DEPENDENCIES) $(OBJ_DIR)))

INCLUDES = $(addprefix -I,$(INC_DIR))
CXXFLAGS = -MMD -W -Werror -Wall -std=c++14 $(INCLUDES)
LDFLAGS = -W -Wall -Werror
LDLIBS = $(addprefix -L,$(DEP_DIR)) $(addprefix -l,$(DEP_LIBS)) $(addprefix -l,$(SYS_LIBS))
CXX = g++
SHELL = /bin/bash

RM_INSTALL_FILES := 

MK_INSTALL_DIR := 

.PHONY: all debug clean fclean re re+ clear run install

all: CXXFLAGS += -O3 
all: LDFLAGS += -O3

debug: CXXFLAGS += -g3
debug: CPPFLAGS += -D__DEBUG__
debug: LDFLAGS += -g3 -D__DEBUG__

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(ARBO):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

-include $(DEPENDENCIES)

$(TARGET): $(BIN_DIR)$(TARGET) | $(ARBO)

$(BIN_DIR)$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

$(OBJ): | $(ARBO)

run: clear debug
	$(BIN_DIR)$(TARGET)

clean:
	$(RM) $(OBJ)
	$(RM) $(DEPENDENCIES)
	$(RM) -r $(ARBO)

fclean: clean
	$(RM) $(TARGET)

re: fclean re_plugins debug

re+: fclean all
	clear
	$(BIN_DIR)$(TARGET)

release: all

clear:
	clear
