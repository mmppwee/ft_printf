/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:09:17 by pwareepo          #+#    #+#             */
/*   Updated: 2023/01/22 18:28:31 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_printf(const char *str, ...)
{
	int	i;
	int	n;
	char *temp;
	va_list	ptr;
	va_start(ptr, str);

	i = 0;
	n = 0;
	i = va_arg(ptr, int);
	printf("%d\n", i);
	temp = va_arg(ptr, char*);
	printf("%s\n", temp);
	i = va_arg(ptr, int);
	printf("%c\n", i);
	// while (str[i] != '\0')
	// {
	// 	if (str[i] == '%')
	// 		ft_check();
	// 	write (1, &str[i], 1);
	// 	i++;
	// }
	va_end(ptr);
	return (n);
}

// void	ft_check(va_list ptr, int i, int n)
// {
// 	if (str[i + 1] == 'c')
// 		n =
// }
int main()
{
	ft_printf("1234", '0', "aaa");
}
