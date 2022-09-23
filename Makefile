# Program name
NAME	= ft_containers
NAME^^	= $(shell echo $(NAME) | tr 'a-z' 'A-Z')

# Directories

INC_DIR	= ./include

# Sources
__SRCS	= $(shell find . -type f -name "*.cpp" | cut -c 3-)
__HEAD	= $(shell find . -type f -name "*.hpp" | cut -c 3-)

SRCS	= $(__SRCS)
OBJS	= $(__SRCS:.cpp=.o)

# Compile
CC		= c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98
INCLUDE	= -I $(INC_DIR)
LIBS	=

# Format

OFFSET		= 25
OFFSET_OBJ	= 60

RESET		= \033[0;0m
FG_BWHIT	= \033[1;97m
FG_WHIT		= \033[0;97m
FG_BGRAY	= \033[1;37m
FG_GRAY		= \033[0;37m
FG_BMAGE	= \033[1;35m
FG_MAGE		= \033[0;35m
FG_BCYAN	= \033[1;36m
FG_CYAN		= \033[0;36m
FG_BGREE	= \033[1;32m
FG_GREE		= \033[0;32m

# Rules
all: $(NAME)

%.o: %.cpp $(__HEAD)
	printf "$(FG_BGRAY)[ $(NAME^^) ] $(FG_BCYAN)OBJ\033[$(OFFSET)G$(FG_BWHIT): $(FG_WHIT)$@ $(FG_BCYAN)\033[$(OFFSET_OBJ)G[.]$(RESET)\r"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	printf "$(FG_BGRAY)[ $(NAME^^) ] $(FG_BCYAN)OBJ\033[$(OFFSET)G$(FG_BWHIT): $(FG_WHIT)$@ $(FG_BGREE)\033[$(OFFSET_OBJ)G[✓]$(RESET)\n"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME) $(LIBS)
	printf "$(FG_BGRAY)[ $(NAME^^) ] $(FG_BGREE)BUILD\033[$(OFFSET)G$(FG_BWHIT): $(FG_BWHIT)$(NAME)$(RESET)\n"

clean:
	rm -f $(OBJS)
	printf "$(FG_BGRAY)[ $(NAME^^) ] $(FG_BMAGE)CLEAN\033[$(OFFSET)G$(FG_BWHIT): $(FG_WHIT).o files cleaned$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	printf "$(FG_BGRAY)[ $(NAME^^) ] $(FG_BMAGE)FCLEAN\033[$(OFFSET)G$(FG_BWHIT): $(FG_WHIT)executable cleaned$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT: