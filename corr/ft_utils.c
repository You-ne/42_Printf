/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:49:55 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 10:49:56 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len(char *s)
{
	int l;

	l = 0;
	if (s)
		while (*s++)
			l++;
	return (l);
}

int		ft_atoi(char *s)
{
	int a;

	a = 0;
	while (is_adig(*s))
		a = (a * 10) + (*s++ - '0');
	return (a);
}

void	ft_putchar(char c, int n, t_fs *fs)
{
	fs->ret += n;
	while (n--)
		write(1, &c, 1);
}

void	ft_putstr(char *s, t_fs *fs)
{
	if (fs->spec == 's' && s)
		while (fs->len--)
			ft_putchar(*s++, 1, fs);
	else if (s)
		while (*s)
			ft_putchar(*s++, 1, fs);
}

void	init_flag(t_fs *fs)
{
	fs->spec = 0;
	fs->len = 0;
	fs->sign = 0;
	fs->point = 0;
	fs->minus = 0;
	fs->precision = 0;
	fs->width = 0;
	fs->out = "OMB";
	fs->zero = 0;
}
