COMPILER = g++
PROJECT = ../run_tests 

CFLAGS += -Wall -I../include/ -std=c++11
LDFLAGS +=

SRCS := tests.cpp \
	matrix.cpp

OBJS := $(SRCS:%.cpp=../obj/%.o)

all: $(PROJECT)

$(PROJECT) : $(OBJS)
	@echo Linking
	@$(COMPILER) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROJECT) 

$(OBJS): ../obj/%.o : ../src/%.cpp
	@echo Compiling
	@$(COMPILER) $(CFLAGS) -c $< -o $@
