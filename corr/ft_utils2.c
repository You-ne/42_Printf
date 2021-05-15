/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:57 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/14 13:40:59 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_star(t_fs *fs, char *s, va_list *ap)
{
	if (*s == '*')
	{
		fs->width = va_arg(*ap, int);
		if (fs->width < 0)
		{
			fs->width *= -1;
			fs->minus = 1;
		}
		s++;
	}
	return (s);
}

int		is_adig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
