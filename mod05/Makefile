CXX      := g++
NAME     := app
ARGS     ?=

SRC_DIR   := src
OBJ_DIR   := obj
BUILD_DIR := build

# Pre-processor
CPPFLAGS := -I$(SRC_DIR) -MMD -MP
# Compiler
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
# Linker flags. Currently empty, but ready for use
LDFLAGS  :=

SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/Bureaucrat.cpp
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(BUILD_DIR)/$(NAME)

# Linking
$(BUILD_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: all
	./$(BUILD_DIR)/$(NAME) $(ARGS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean:
	rm -rf $(BUILD_DIR) $(OBJ_DIR)

re: fclean all

-include $(DEPS)
