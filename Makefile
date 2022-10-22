# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 21:59:51 by misikogl          #+#    #+#              #
#    Updated: 2022/10/10 22:37:09 by misikogl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror 

SRCS	= ./srcs/main.c \
	  ./srcs/read_map.c \
	  ./srcs/validate.c \
	  ./srcs/identfy_objects.c \
	  ./srcs/render_map.c \
	  ./srcs/player_movement.c \
	  ./srcs/input_control.c \
	  ./srcs/floodfill.c

OBJS	= $(SRCS:%.c=%.o)

$(NAME):$(OBJS)
		make -C ./libs/mlx
		mv ./libs/mlx/libmlx.a ./libmlx.a

		make -C ./libs/libft
		mv ./libs/libft/libft.a ./libft.a

		make -C ./libs/ft_printf
		mv ./libs/ft_printf/libftprintf.a ./libftprintf.a
		$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a libft.a libftprintf.a -o $(NAME)
all: 	$(NAME)

clean:
		make -C ./libs/mlx clean
		rm -rf */*.o libmlx.a so_long.o

		make -C ./libs/libft fclean
		rm -rf */*.o libft.a

		make -C ./libs/ft_printf fclean
		rm -rf */*.o libftprintf.a
		
fclean: clean
		rm -rf so_long

re: 	fclean all

.PHONY: all clean fclean re
