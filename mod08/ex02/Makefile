CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = mutantstack
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)
