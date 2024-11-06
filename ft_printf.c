/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palaca <palaca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:41:33 by palaca            #+#    #+#             */
/*   Updated: 2024/11/06 05:06:25 by palaca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putchar (char a)
{
	write(1, &a, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr (int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		ft_putstr('-2147483648');
		return (11);
	}
	if (nb < 0)
		nb *= -1;
	if (nb < 9 && nb > 0)
		i += ft_putchar(nb);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i);
}


int ft_control(char c, va_list l)
{
	if (c == 'c')
		return (ft_putchar(va_arg(l, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(l, char)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd')
		return (ft_putnbr(va_arg(l, int)));

}



int ft_printf(const char *s, ...)
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
	return(len);
}

#include <stdio.h>
int main()
{
	printf("sa");
}