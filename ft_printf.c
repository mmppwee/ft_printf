/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:09:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/11 15:54:11 by pwareepo         ###   ########.fr       */
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
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_hex_lower(unsigned int nb)
{
	int	n;

	n = 0;
	if (nb >= 16)
	{
		n = ft_hex_lower(nb / 16);
		n += ft_hex_lower(nb % 16);
	}
	else
		n = ft_putchar("0123456789abcdef"[nb % 16]);
	return (n);
}

int	ft_printp(unsigned long nb, int x)
{
	int	n;

	n = 2;
	if (x == 0)
		ft_putstr("0x");
	if (nb >= 16)
	{
		n = ft_printp(nb / 16, 1);
		n += ft_printp(nb % 16, 1);
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
		n += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		nb = -nb;
		n += ft_putchar('-');
		n += ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		n = ft_putnbr(nb / 10);
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
		n = ft_printu(nb / 10);
		n += ft_printu(nb % 10);
	}
	else
		n += ft_putchar(nb + '0');
	return (n);
}


int	ft_hex_upper(unsigned int nb)
{
	int	n;

	n = 0;
	if (nb >= 16)
	{
		n = ft_hex_upper(nb / 16);
		n += ft_hex_upper(nb % 16);
	}
	else
		n = ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (n);
}

int	ft_check(const char *str, va_list ptr, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ptr, char*)));
	else if (str[i + 1] == 'p')
	{
		return (2+ft_printp(va_arg(ptr, unsigned long), 0));
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (str[i + 1] == 'u')
		return (ft_printu(va_arg(ptr, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_hex_lower(va_arg(ptr, unsigned int)));
	else if (str[i + 1] == 'X')
		return (ft_hex_upper(va_arg(ptr, unsigned int)));
	else if (str[i + 1] == '%')
		return (ft_putchar('%'));
	else
		return (1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	n;
	va_list	ptr;
	va_start(ptr, str);

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			n += ft_check(str, ptr,i);
			i++;
		}
		else
			n += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (n);
}

// int main()
// {
// 	ft_printf("%s\n", NULL);
// }
