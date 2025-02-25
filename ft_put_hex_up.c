/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:36 by zivanov           #+#    #+#             */
/*   Updated: 2024/12/18 13:45:34 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

static int	ft_sign_digits(unsigned int nbr)
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

static int	ft_itohexa(unsigned int nbr, int sign_digits, int char_read)
{
	char	*nbr_to_str;
	char	*hex_base_up;

	hex_base_up = "0123456789ABCDEF";
	nbr_to_str = (char *)malloc(sign_digits + 1);
	if (nbr_to_str == NULL)
		return (-1);
	nbr_to_str[sign_digits] = '\0';
	while (nbr)
	{
		nbr_to_str[sign_digits - 1] = hex_base_up[(nbr % 16)];
		nbr /= 16;
		sign_digits--;
	}
	char_read = ft_put_str(nbr_to_str, char_read);
	free(nbr_to_str);
	return (char_read);
}

int	ft_put_hex_up(unsigned int nbr, int char_read)
{
	if (nbr == 0)
		return (ft_put_char('0', char_read));
	else
		return (ft_itohexa(nbr, ft_sign_digits(nbr), char_read));
}
