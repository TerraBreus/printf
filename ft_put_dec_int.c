/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dec_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:39:04 by zivanov           #+#    #+#             */
/*   Updated: 2024/11/19 11:13:25 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_sign_digits(int nbr)
{
	int	sign_digits;

	sign_digits = 0;
	while (nbr)
	{
		sign_digits++;
		nbr /= 10;
	}
	return (sign_digits);
}

static int	ft_itoa(int nbr, int is_neg, int sign_digits, int char_read)
{
	char	*nbr_to_str;

	nbr_to_str = (char *)malloc(sign_digits + is_neg + 1);
	if (nbr_to_str == NULL)
		return (-1);
	nbr_to_str[sign_digits + is_neg] = '\0';
	if (is_neg)
		nbr_to_str[0] = '-';
	while (nbr)
	{
		nbr_to_str[sign_digits + is_neg - 1] = (nbr % 10) + '0';
		nbr /= 10;
		sign_digits--;
	}
	char_read = ft_put_str(nbr_to_str, char_read);
	free(nbr_to_str);
	return (char_read);
}

int	ft_put_dec_int(int nbr, int char_read)
{
	if (nbr == -2147483648)
		return (ft_put_str("-2147483648", char_read));
	else if (nbr == 0)
		return (ft_put_char('0', char_read));
	else if (nbr < 0)
		return (ft_itoa((nbr * -1), 1, ft_sign_digits(nbr), char_read));
	else if (nbr > 0)
		return (ft_itoa(nbr, 0, ft_sign_digits(nbr), char_read));
	return (-1);
}
