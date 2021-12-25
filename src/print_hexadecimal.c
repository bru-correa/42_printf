/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:48:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/25 16:02:36 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_in_hexa(unsigned int n, char *base);
int	print_pointer(void *pointer);

int	print_hexadecimal(unsigned int n, const char flag)
{
	char	*base;

	if (flag == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (write_in_hexa(n, base));
}

static int	write_in_hexa(unsigned int n, char *base)
{
	static int		write_count;

	write_count = 0;
	if (n >= 16)
		write_in_hexa(n / 16, base);
	write(1, &base[n % 16], 1);
	write_count++;
	return (write_count);
}
