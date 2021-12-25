/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:48:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/25 16:51:15 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_in_hexa(unsigned long int n, char *base);

int	print_hexadecimal(unsigned int n, const char flag)
{
	char	*base;

	if (flag == 'x')
		base = HEXA_LOWER;
	else
		base = HEXA_UPPER;
	return (write_in_hexa(n, base));
}

int	print_pointer(void *ptr)
{
	long int	*address;
	int			write_count;

	if (!ptr)
	{
		if (IS_MACOS)
			return (write(1, "(nil)", 5));
		else
			return (write (1, "0x0", 3));
	}
	address = (long int *)&ptr;
	write_count = write (1, "0x", 2);
	write_count += write_in_hexa(*address, HEXA_LOWER);
	return (write_count);
}

static int	write_in_hexa(unsigned long int n, char *base)
{
	static int		write_count;

	write_count = 0;
	if (n >= 16)
		write_in_hexa(n / 16, base);
	write(1, &base[n % 16], 1);
	write_count++;
	return (write_count);
}
