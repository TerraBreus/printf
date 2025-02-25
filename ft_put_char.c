/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:10:11 by zivanov           #+#    #+#             */
/*   Updated: 2024/11/13 13:01:08 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

//Simple small check whether we are getting a valid, printable character...
//...since we are passing it as an integer. FYI: We're never printing '\0'.

int	ft_put_char(int c, int char_read)
{
	char	character;

	character = (char)c;
	write(1, &character, 1);
	return (char_read + 1);
}
