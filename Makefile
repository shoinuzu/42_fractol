# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 10:26:28 by abarbosa          #+#    #+#              #
#    Updated: 2022/09/06 14:58:41 by abarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fract-ol

SRCS	=	ft_fractol.c		\
			ft_complex.c		\
			ft_utils.c			\
			ft_mandelbrot.c		\
			ft_memcmp.c			\
			ft_draw_box.c		\
			ft_statics.c		\

OBJS	=	$(SRCS:.c=.o)
LIB		=	./minilibx-linux/libmlx_Linux.a

COMPILE	=	gcc -g -fsanitize=address -Wall -Wextra -Werror -O3

REMOVE	=	rm -f

.c.o:
		$(COMPILE)  -c $< -o $@

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)	

all:		$(NAME)

clean:
			$(REMOVE) $(OBJS)

fclean:		clean
			$(REMOVE) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
