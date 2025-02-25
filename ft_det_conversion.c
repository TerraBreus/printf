/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_det_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:52 by zivanov           #+#    #+#             */
/*   Updated: 2024/12/18 13:44:42 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_det_conversion(const char *str, va_list ap, int char_read)
{
	if (*str == 'c')
		return (ft_put_char(va_arg(ap, int), char_read));
	else if (*str == 's')
		return (ft_put_str(va_arg(ap, char *), char_read));
	else if (*str == 'p')
		return (ft_put_point(va_arg(ap, void *), char_read));
	else if (*str == 'd')
		return (ft_put_dec_int(va_arg(ap, int), char_read));
	else if (*str == 'i')
		return (ft_put_dec_int(va_arg(ap, int), char_read));
	else if (*str == 'u')
		return (ft_put_uns(va_arg(ap, unsigned int), char_read));
	else if (*str == 'x')
		return (ft_put_hex_low(va_arg(ap, unsigned int), char_read));
	else if (*str == 'X')
		return (ft_put_hex_up(va_arg(ap, unsigned int), char_read));
	else if (*str == '%')
		return (ft_put_char('%', char_read));
	return (-1);
}
