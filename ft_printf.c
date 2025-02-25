/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:29:11 by zivanov           #+#    #+#             */
/*   Updated: 2024/11/13 12:47:32 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		char_read;
	va_list	ap;

	va_start(ap, str);
	char_read = 0;
	while (*str && !(char_read == -1))
	{
		if (*str == '%')
			char_read = ft_det_conversion((++str), ap, char_read);
		else
			char_read = ft_put_char(*str, char_read);
		str++;
	}
	va_end(ap);
	return (char_read);
}
