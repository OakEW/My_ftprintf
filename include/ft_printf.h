#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(long nb);
int	ft_print_hex(unsigned int nb, char format);
int	ft_put_ptr(uintptr_t ads);
int	ft_print_ptr(uintptr_t ads);
int ft_print_format(va_list args, const char format);

#endif