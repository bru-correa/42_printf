/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:04:03 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/25 16:49:12 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define HEXA_LOWER	"0123456789abcdef"
# define HEXA_UPPER	"0123456789ABCDEF"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

/* JUST FOR TESTING */
int		ft_vprintf(const char *input, va_list args);
/* JUST FOR TESTING */
int		ft_printf(const char *input, ...);
int		print_char(int character);
int		print_string(char *str);
int		print_decimal(long int decimal);
int		count_digits(long int n);
char	*ft_litoa(long int n);
int		print_hexadecimal(unsigned int n, const char flag);
int		print_pointer(void *ptr);
#endif
