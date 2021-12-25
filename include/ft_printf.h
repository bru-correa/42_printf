/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:04:03 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/25 15:51:57 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

/* JUST FOR TESTING */
int		ft_vprintf(const char *input, va_list args);
/* JUST FOR TESTING */
int		ft_printf(const char *input, ...);
int		print_char(int character);
int		print_string(char *str);
int		print_decimal(long int decimal);
int		count_digits(long int n);
char	*ft_litoa(long int n);
int		print_hexadecimal(int n, const char flag);
#endif
