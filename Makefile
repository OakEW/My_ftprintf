# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:42:06 by ywang2            #+#    #+#              #
#    Updated: 2025/11/25 10:38:13 by ywang2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

CFILES = $(addprefix $(SRCS_DIR), $(SRCS))

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

INCLUDES = -I ./include

SRCS_DIR = ./src/

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc -c $(CFLAGS) $(INCLUDES) $< -o $@

$(NAME): $(OFILES)
	ar crs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
