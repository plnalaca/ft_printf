/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palaca <palaca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:11:07 by palaca            #+#    #+#             */
/*   Updated: 2024/11/07 20:42:33 by palaca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_control(char c, va_list l);
int	ft_printf(const char *s, ...);
int	ft_putchar(char a);
int	ft_putstr(char *str);
int	ft_putnbr(long nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthex(unsigned int nb, char x);
int	ft_putpoint(unsigned long nb);

#endif