#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
		ft_putchar(str[i]);
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
		ft_putstr("-2147483648");
		return (11);
	}
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
		i += ft_putchar(nb);
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int ft_puthex(unsigned int nb, char x)
{
	int i;

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
		else if(x == 'X')
			i += ft_putchar(nb - 10 + 'A');
	}
	return (i);
}

int	ft_putpoint (unsigned long long nb)
{
	int i;

	i = 0;
	i =+ ft_putstr("0x");
	if (nb == 0)
		i += ft_putchar('0');
	if (nb >= 16)
	{
		i += ft_putpoint(nb / 16);
		i += ft_putpoint(nb % 16);
	}
	else if (nb <= 9)
		i += ft_putpoint(nb + '0');
	else
			i += ft_putchar(nb - 10 + 'a');
	return (i);
}

int ft_control(char c, va_list l)
{
	if (c == 'c')
		return (ft_putchar(va_arg(l, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(l, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd'|| c == 'i')
		return (ft_putnbr(va_arg(l, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(l, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(l, unsigned int), c));
	else if (c == 'p')
		return (ft_putpoint(va_arg(l, unsigned long long)));
	return (0);
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



int main()
{
	int *a = {12,53,34};
	printf("\n%p\n", a);
	ft_printf("\n%p\n", a);
}