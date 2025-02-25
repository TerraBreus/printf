/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:44:57 by zivanov           #+#    #+#             */
/*   Updated: 2024/12/18 13:44:26 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	ft_sign_digits(unsigned long nbr)
{
	int	sign_digits;

	sign_digits = 0;
	while (nbr)
	{
		sign_digits++;
		nbr /= 16;
	}
	return (sign_digits);
}

static int	ft_ultoa_hex(unsigned long nbr, int sign_digits, int char_read)
{
	char	*nbr_to_str;
	char	*hex_base_low;

	hex_base_low = "0123456789abcdef";
	nbr_to_str = (char *)malloc(sign_digits + 1);
	if (nbr_to_str == NULL)
		return (-1);
	nbr_to_str[sign_digits] = '\0';
	while (nbr)
	{
		nbr_to_str[sign_digits - 1] = hex_base_low[(nbr % 16)];
		nbr /= 16;
		sign_digits--;
	}
	char_read = ft_put_str(nbr_to_str, char_read);
	free(nbr_to_str);
	return (char_read);
}

int	ft_put_point(void *ptr, int char_read)
{
	unsigned long	mem_address;

	if (ptr == NULL)
		return (ft_put_str("(nil)", char_read));
	mem_address = (unsigned long) ptr;
	char_read = ft_put_str("0x", char_read);
	char_read = ft_ultoa_hex(mem_address, \
	ft_sign_digits(mem_address), char_read);
	return (char_read);
}
