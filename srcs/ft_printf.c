/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:43:49 by ywang2            #+#    #+#             */
/*   Updated: 2025/11/17 16:12:30 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long long ads)
{
	int	len;

	len = 0;
	if (ads > 15)
	{
		len = ft_put_ptr(ads / 16);
		ft_put_ptr(ads % 16);
	}
	else
	{
		if (ads < 10)
			ft_print_char(ads % 16 + '0');
		if (ads >= 10)
			ft_print_char(ads % 16 - 10 + 'a');
	}
	len++;
	return (len);
}

int	ft_print_ptr(unsigned long long ads)
{
	int	len;

	len = 2;
	write (1, "0x", 2);
	len += ft_put_ptr(ads);
	return (len);
}

int	ft_print_format(va_list args, const char format)
{
	int	total;

	total = 0;
	if (format == 'c')
		total += ft_print_char(va_arg(args, int));
	else if (format == 's')
		total += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		total += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		total += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		total += ft_print_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		total += ft_print_hex(va_arg(args, int), format);
	else if (format == '%')
		otal += ft_print_char('%');
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			total += ft_print_format(args, *str);
		}
		else
			total += ft_print_char(*str);
		str++;
	}
	va_end(args);
	return (total);
}
/*#include<stdio.h>
int main(void)
{
	//char *m = NULL;

    //ft_printf(" return ft_ = %d\n", ft_printf(" %%"));
	printf("return Std = %zd\n", write (1, "\001\002\007\v\010\f\r\nv",9));
	//ft_printf(" return Std = %d\n", ft_printf("%%%c", 'x'));
	//printf("%lx\n", ads);
	//ft_printf("%X\n", 16);
	//ft_printf("return ft_ = %d\n", ft_printf("%X", -15123));
	//printf(" return v =%d\n", printf("%u",  -4534543121231));
    //printf("%s", m); // if char * is NULL, actually print "(null)" , 6 bytes
}*/