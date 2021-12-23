/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:04:03 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/15 16:33:51 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

/* JUST FOR TESTING */
int	ft_vprintf(const char *input, va_list args);
/* JUST FOR TESTING */
int	ft_printf(const char *input, ...);
int	print_char(int character);
int	print_string(char *str);
#endif
