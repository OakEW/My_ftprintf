/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:43:49 by ywang2            #+#    #+#             */
/*   Updated: 2025/11/30 15:43:11 by ywang2           ###   ########.fr       */
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
	if (!ads)
	{
		write (1, "(nil)", 5);
		return (5);
	}
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
		total += ft_print_char('%');
	else
	{
		total += ft_print_char('%');
		total += ft_print_char(format);
	}
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		total;
	va_list	args;

	total = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 0)
			return (-1);
		else if (*str == '%')
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
// #include <stdio.h>
// #include "./include/ft_printf.h"

// int	main(void)
// {
// 	printf (":_std_return = %d\n", printf ("%%%%%"));
// 	printf ("--------\n");
// 	printf (":__ft_return = %d\n", ft_printf ("%%%%%"));
// }
