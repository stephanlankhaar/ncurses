CC := g++
CFLAGS := -lncurses
TARGET := test

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp, $(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -c $@ -lncurses
