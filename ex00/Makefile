NAME     = claptrap
SRC_DIR  = src
INC_DIR  = incl
OBJ_DIR  = obj
SRC      = ClapTrap.cpp main.cpp
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPS     = $(OBJS:.o=.d)
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR) -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re