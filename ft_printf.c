/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:09:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/11 16:16:50 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *str, va_list ptr, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (str[i + 1] == 'p')
		return (2 + ft_printp(va_arg(ptr, unsigned long), 0));
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
	int		i;
	int		n;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			n += ft_check(str, ptr, i);
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
