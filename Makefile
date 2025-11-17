SRCS = ft_printf.c 

CFILES = $(addprefix $(SRCS_DIR), $(SRCS))

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

INCLUDES = -I ./include

SRCS_DIR = ./srcs/

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
