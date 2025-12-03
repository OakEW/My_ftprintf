/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:35 by ywang2            #+#    #+#             */
/*   Updated: 2025/12/01 15:42:11 by ywang2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != 0)
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(long nb)
{
	int	len;
	int	neg;

	len = 0;
	neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		ft_print_char('-');
		neg = 1;
	}
	if (nb > 9)
		len = ft_print_nbr(nb / 10);
	ft_print_char(nb % 10 + '0');
	len++;
	return (len + neg);
}

int	ft_print_hex(unsigned int nb, char format)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len = ft_print_hex(nb / 16, format);
		ft_print_hex(nb % 16, format);
	}
	else
	{
		if (nb < 10)
			ft_print_char(nb % 16 + '0');
		else if (nb >= 10)
			ft_print_char((nb % 16) - 10 + format - 23);
	}
	len++;
	return (len);
}
