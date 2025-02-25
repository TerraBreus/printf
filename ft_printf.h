/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:30:06 by zivanov           #+#    #+#             */
/*   Updated: 2024/12/18 13:44:48 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_det_conversion(const char *str, va_list ap, int char_read);
int	ft_put_char(int c, int char_read);
int	ft_put_str(char *str, int char_read);
int	ft_put_dec_int(int nbr, int char_read);
int	ft_put_uns(unsigned int nbr, int char_read);
int	ft_put_hex_low(unsigned int nbr, int char_read);
int	ft_put_hex_up(unsigned int nbr, int char_read);
int	ft_put_point(void *ptr, int char_read);
