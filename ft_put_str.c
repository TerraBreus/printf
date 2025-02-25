/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:18:50 by zivanov           #+#    #+#             */
/*   Updated: 2024/11/13 13:14:51 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_put_str(char *str, int char_read)
{
	if (str == NULL)
		return (ft_put_str("(null)", char_read));
	while (*str && !(char_read == -1))
	{
		char_read = ft_put_char(*str, char_read);
		str++;
	}
	return (char_read);
}
