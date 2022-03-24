COMPILER = g++

PROJECT = linear

CFLAGS += -Wall -Iinclude/ -std=c++11
LDFLAGS +=

SRCS := main.cpp \
	matrix.cpp

OBJS := $(SRCS:%.cpp=obj/%.o)

all: dirs $(PROJECT) $(HEADERS)

dirs:
	@mkdir -p obj

$(PROJECT) : $(OBJS)
	@echo Linking
	@$(COMPILER) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROJECT) 

$(OBJS): obj/%.o : src/%.cpp
	@echo Compiling
	@$(COMPILER) $(CFLAGS) -c $< -o $@

force: clean all;

clean:
	rm -f $(OBJS)
	rm -f $(PROJECT)
