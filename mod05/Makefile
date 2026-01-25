CXX      := g++
NAME     := app
ARGS     ?=
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Colors
GREEN   := \033[1;32m
YELLOW  := \033[1;33m
BLUE    := \033[1;34m
MAGENTA := \033[1;35m
RESET   := \033[0m

# Verbose Mode
ifndef V
    Q := @
else
    Q :=
endif

ifdef sanitize
    CXXFLAGS   += -fsanitize=address -fno-omit-frame-pointer
    LDFLAGS    += -fsanitize=address
endif

# Directories
SRC_DIR    := src
OBJ_DIR    := obj
BUILD_DIR  := build

# Pre-processor
CPPFLAGS := -I$(SRC_DIR) -MMD -MP
LDFLAGS  +=

# Relative to src/
FILES := main.cpp Bureaucrat.cpp

# Auto-generate full paths
SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS := $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))
DEPS := $(OBJS:.o=.d)

# Safety Net
.DELETE_ON_ERROR:

.PHONY: all clean fclean re run help

all: $(NAME)

$(NAME): $(BUILD_DIR)/$(NAME)

# Linking
$(BUILD_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)Linking $(NAME)...$(RESET)\n"
	$(Q)$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	@printf "$(GREEN)Build successful! Binary: $@$(RESET)\n"

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling $<...$(RESET)\n"
	$(Q)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(NAME)
	@printf "$(MAGENTA)Running $(NAME)...$(RESET)\n"
	./$(BUILD_DIR)/$(NAME) $(ARGS)

clean:
	@printf "$(YELLOW)Cleaning objects...$(RESET)\n"
	$(Q)rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(YELLOW)Removing executables...$(RESET)\n"
	$(Q)rm -rf $(BUILD_DIR)

re: fclean all

help:
	@printf "$(MAGENTA)Available targets:$(RESET)\n"
	@printf "  $(GREEN)make$(RESET)            : Build executable\n"
	@printf "  $(GREEN)make sanitize=1$(RESET) : Build with ASan\n"
	@printf "  $(GREEN)make run$(RESET)        : Run the executable\n"

-include $(DEPS)
