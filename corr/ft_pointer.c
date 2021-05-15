/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:49:30 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 10:49:31 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex_p(size_t n, t_fs *fs)
{
	if (n > 15)
		print_hex_p(n / 16, fs);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + 48, 1, fs);
}

void		print_p(t_fs *fs)
{
	if (!fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
	if (fs->pt == 0)
	{
		ft_putstr("(nil)", fs);
	}
	if (fs->pt > 0)
	{
		ft_putstr("0x", fs);
		print_hex_p(fs->pt, fs);
	}
	if (fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
}

int			ptlen(unsigned int u)
{
	int length;

	length = 1;
	while (u > 15)
	{
		u /= 16;
		length++;
	}
	return (length);
}

void		correct_p(t_fs *fs)
{
	fs->len = ptlen(fs->pt) + 2;
	fs->len = fs->pt == 0 ? 5 : fs->len;
	fs->len = (fs->point && fs->len > fs->precision) ? fs->precision : fs->len;
	fs->width -= (fs->width > fs->len) ? fs->len : fs->width;
}
