CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = main
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

DEBUG ?= 0

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -DDEBUG=$(DEBUG) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

debug:
	$(MAKE) DEBUG=1

.PHONY: clean debug
.SECONDARY: $(OBJ)
