/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:53:01 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/12/24 17:17:12 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_decimal(unsigned long int decimal)
// {
// 	ft_putnbr_fd(decimal, 1);
// 	return(count_digits(decimal));
// }

int	print_decimal(long int decimal)
{
	char	*printable_number;
	int		digits_count;

	printable_number = ft_litoa(decimal);
	digits_count = ft_strlen(printable_number);
	ft_putstr_fd(printable_number, 1);
	free(printable_number);
	return (digits_count);
}
