# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 15:10:17 by pwareepo          #+#    #+#              #
#    Updated: 2023/01/15 16:50:48 by pwareepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS =$(SRCS:.c = .o)
all: $(NAME)
%o: %c
	gcc $(FLAGS) -c $< -o $@
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
