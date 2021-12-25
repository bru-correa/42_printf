/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:17:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/25 15:54:40 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_flags(const char *input, va_list args);

int	printf_loop(const char *input, va_list args, int length)
{
	length = 0;
	while (*input != '\0')
	{
		if (*input == '%' && ft_strchr("cspudixX%", *(input + 1)))
		{
			input++;
			length += handle_flags(input, args);
		}
		else
		{
			if (*input == '\\' && ft_strchr((input + 1), '%'))
			{
				length += write(1, input, 2);
				input++;
			}
			else
				length += write(1, input, 1);
		}
		input++;
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	int			length;
	va_list		args;

	length = 0;
	va_start(args, input);
	length = printf_loop(input, args, length);
	va_end(args);
	return (length);
}

// JUST FOR TESTING
int	ft_vprintf(const char *input, va_list args)
{
	int	length;

	length = 0;
	length = printf_loop(input, args, length);
	return (length);
}

int	handle_flags(const char *input, va_list args)
{
	int	length;

	if (*input == 'c')
		length = print_char(va_arg(args, int));
	else if (*input == 's')
		length = print_string(va_arg(args, char *));
	else if (*input == 'd' || *input == 'i')
		length = print_decimal(va_arg(args, int));
	else if (*input == 'u')
		length = print_decimal(va_arg(args, unsigned int));
	else if (*input == 'x' || *input =='X')
		length = print_hexadecimal(va_arg(args, int), *input);
	else
	{
		ft_putchar_fd('%', 1);
		length = 1;
	}
	return (length);
}
