NAME = so_long
NAME_BONUS = bonus_part/so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror


COMPI = -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c get_next_line.c get_next_line_utils.c ft_split_map.c game_manager.c \
move_manager.c movement.c error_manager.c flood_fill.c ft_printf.c ft_putchar.c \
ft_convert_hex.c ft_putnbr.c ft_putnbr_unsigned.c ft_putstr.c ft_split.c ft_strcmp.c ft_substr.c
BONUS = bonus_part/so_long_bonus.c bonus_part/get_next_line.c bonus_part/get_next_line_utils.c \
bonus_part/ft_split_map.c bonus_part/move_manager.c bonus_part/movement.c bonus_part/error_manager.c\
 bonus_part/flood_fill.c bonus_part/ft_printf.c bonus_part/ft_putchar.c bonus_part/ft_convert_hex.c \
 bonus_part/ft_putnbr.c bonus_part/ft_putnbr_unsigned.c bonus_part/ft_putstr.c bonus_part/animation.c \
 bonus_part/game_manager.c bonus_part/ft_itoi.c bonus_part/ft_strjoin_normal.c bonus_part/enemy_manager.c \
 bonus_part/ft_split.c bonus_part/ft_strcmp.c bonus_part/ft_substr.c

OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(COMPI) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(COMPI) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ_SRC) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all bonus

.PHONY:	 all clean fclean re bonus