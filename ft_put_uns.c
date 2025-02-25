/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:19 by zivanov           #+#    #+#             */
/*   Updated: 2024/11/13 13:02:59 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	ft_sign_digits(unsigned int nbr)
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

static int	ft_uitoa(unsigned int nbr, int sign_digits, int char_read)
{
	char	*uns_to_str;

	uns_to_str = (char *)malloc(sign_digits + 1);
	if (uns_to_str == NULL)
		return (-1);
	uns_to_str[sign_digits] = '\0';
	while (nbr)
	{
		uns_to_str[sign_digits - 1] = (nbr % 10) + '0';
		nbr /= 10;
		sign_digits--;
	}
	char_read = ft_put_str(uns_to_str, char_read);
	if (uns_to_str)
		free(uns_to_str);
	return (char_read);
}

int	ft_put_uns(unsigned int nbr, int char_read)
{
	if (nbr == 0)
		return (ft_put_char('0', char_read));
	else
		return (ft_uitoa(nbr, ft_sign_digits(nbr), char_read));
}
