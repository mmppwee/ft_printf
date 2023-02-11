/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:15:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/11 16:20:14 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
