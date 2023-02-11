/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:26:02 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/11 16:20:35 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printp(unsigned long nb, int x);
int	ft_putnbr(int nb);
int	ft_printu(unsigned int nb);
int	ft_hex_lower(unsigned int nb);
int	ft_hex_upper(unsigned int nb);

#endif
