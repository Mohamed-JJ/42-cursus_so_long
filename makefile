NAME = so_long
BONUS = so_long_bonus
CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS	= $(SOURCE:.c=.o)

OBJECTS_BNS	= $(SOURCE_BNS:.c=.o)

RM = rm -f

SOURCE_BNS = ft_split__bonus.c \
			get_next_line__bonus.c \
			get_next_line_utils__bonus.c \
			map_check__bonus.c \
			drawing__bonus.c \
			helping__bonus.c \
			moving__bonus.c \
			drawing2__bonus.c \
			main__bonus.c \
			check_path__bonus.c \

SOURCE = ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
			map_check.c \
			drawing.c \
			helping.c \
			moving.c \
			drawing2.c \
			main.c \
			check_path.c \


%.o : %.c so_long.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS) 
	@$(CC) $(FLAGS) $(OBJECTS) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

bonus : $(OBJECTS_BNS)
	@$(CC) $(FLAGS) $(OBJECTS_BNS) -lmlx -framework OpenGl -framework Appkit -o $(BONUS)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS) $(OBJECTS_BNS)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY : re clean all fclean