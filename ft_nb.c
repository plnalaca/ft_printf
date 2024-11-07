/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palaca <palaca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:37:13 by palaca            #+#    #+#             */
/*   Updated: 2024/11/07 21:03:54 by palaca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{	
		nb *= -1;
		ft_putchar('-');
		i++;
	}
	if (nb <= 9 && nb >= 0)
		i += ft_putchar(nb + '0');
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 9 && nb >= 0)
		i += ft_putchar(nb + '0');
	else 
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_puthex(unsigned int nb, char x)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_puthex(nb / 16, x);
		i += ft_puthex(nb % 16, x);
	}
	else if (nb <= 9)
		i += ft_putchar(nb + '0');
	else
	{
		if (x == 'x')
			i += ft_putchar(nb - 10 + 'a');
		else if (x == 'X')
			i += ft_putchar(nb - 10 + 'A');
	}
	return (i);
}

int	ft_putpoint(unsigned long nb)
{
	int	i;

	i = 0;
	
	
	if (nb == 0)
		i += ft_putstr("(nil)");
	if (nb >= 16)
	{
		i += ft_putstr("0x");
		i += ft_putpoint(nb / 16);
		i += ft_putpoint(nb % 16);
	}
	else 
	{
		if (nb <= 9)
		i += ft_putchar(nb + '0');
		else
		i += ft_putchar(nb - 10 + 'a');
	}
	return (i);
}
