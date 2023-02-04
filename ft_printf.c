/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:09:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/04 18:30:15 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printp(unsigned long nb)
{
	int	n;

	n = 0;
	if (nb >= 16)
	{
		n = ft_printp(nb / 16);
		n += ft_printp(nb % 16);
	}
	else
		n = ft_putchar("0123456789abcdef"[nb]);
	return (n);
}

int	ft_putnbr(int nb)
{
	int	n;

	n = 0;
	if (nb == -2147483648)
	{
		n += ft_putchar('-');
		n += ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		nb = -nb;
		n += ft_putchar('-');
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		n += ft_putnbr(nb / 10);
		n += ft_putnbr(nb % 10);
	}
	else
		n += ft_putchar(nb + '0');
	return (n);
}

int	ft_printu(unsigned int nb)
{
	int	n;

	n = 0;
	if (nb >= 10)
	{
		n += ft_printu(nb / 10);
		n += ft_printu(nb % 10);
	}
	else
		n += ft_putchar(nb + '0');
	return (n);
}

int	ft_hex_lower()

int	ft_check(const char *str, va_list ptr)
{
	int	i;

	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ptr, char*)));
	if (str[i + 1] == 'p')
		return (ft_printp(va_arg(ptr, unsigned long)));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	if (str[i + 1] == 'u')
		return (ft_printu(va_arg(ptr, unsigned int)));
	if (str[i + 1] == 'x')
		return (ft_hex_lower(va_arg(ptr, unsigned int)));
	if (str[i + 1] == 'X')
		return (ft_hex_upper(va_arg(ptr, unsigned int)));
	if (str[i + 1] == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	n;
	// char *temp;
	va_list	ptr;
	va_start(ptr, str);

	i = 0;
	n = 0;
	// i = va_arg(ptr, int);
	// printf("%d\n", i);
	// temp = va_arg(ptr, char*);
	// printf("%s\n", temp);
	// i = va_arg(ptr, int);
	// printf("%c\n", i);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			n += ft_check(str, ptr);
		n += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (n);
}

int main()
{
	ft_printf("%s\n", "aaaaaa");
}
