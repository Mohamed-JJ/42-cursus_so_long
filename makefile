NAME = so_long.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g -Ofast

OBJECTS	= $(SOURCE:.c=.o)

RM = rm -f

SOURCE = ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
			map_check.c \
			drawing.c \
			helping.c \
			moving.c \
			drawing2.c \
			main.c \
			# check_path.c \


%.o : %.c so_long.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)


all: $(NAME)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
