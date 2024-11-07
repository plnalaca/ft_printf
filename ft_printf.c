/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palaca <palaca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:55:39 by palaca            #+#    #+#             */
/*   Updated: 2024/11/08 02:11:11 by palaca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list l)
{
	int	i;

	i = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(l, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(l, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(l, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(l, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(l, unsigned int), c));
	else if (c == 'p')
		return (ft_putpoint(va_arg(l, unsigned long)));
	else
	{
		i += ft_putchar('%');
		i += ft_putchar(c);
		return (i);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			len += ft_control(s[i + 1], list);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}
