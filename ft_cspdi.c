/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:15:29 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/11 16:19:49 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
