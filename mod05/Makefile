CXX      := g++
NAME     := webserve
ARGS     ?=

BUILD_DIR := bin
SRC_DIR   := src
OBJ_DIR   := obj

# Pre-processor
CPPFLAGS := -I$(SRC_DIR) -MMD -MP
# Compiler
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
# Linker flags. Currently empty, but ready for use
LDFLAGS  :=

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean fclean re run

all: $(BUILD_DIR)/$(NAME)

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
