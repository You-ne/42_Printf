/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:39:03 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 11:39:05 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(int n)
{
	int l;

	l = 1;
	while (n / 10)
	{
		n /= 10;
		l++;
	}
	return (l);
}

void	correct_dec(t_fs *fs)
{
	fs->len = nbrlen(fs->d);
	if (fs->d < 0)
		fs->sign = 1;
	fs->l = fs->sign ? -(long)fs->d : (long)fs->d;
	if (!fs->l && fs->point && fs->precision == 0)
		fs->len = 0;
	fs->precision -= (fs->precision > fs->len) ? fs->len : fs->precision;
	fs->width -= (fs->width > fs->precision + fs->len + fs->sign) ? \
	fs->precision + fs->len + fs->sign : fs->width;
	print_dec(fs);
}

void	ft_putnbr(long l, t_fs *fs)
{
	if (l > 9)
		ft_putnbr(l / 10, fs);
	ft_putchar((l % 10) + '0', 1, fs);
}

void	print_dec(t_fs *fs)
{
	(fs->sign && !fs->precision && !fs->width) || \
	(fs->sign && !fs->precision && fs->zero) ? ft_putchar('-', 1, fs) : 0;
	if (!fs->minus)
	{
		if (fs->width)
			fs->zero ? ft_putchar('0', fs->width, fs) : \
			ft_putchar(' ', fs->width, fs);
	}
	(fs->sign && fs->precision) || (fs->sign && fs->width && !fs->zero) ? \
	ft_putchar('-', 1, fs) : 0;
	fs->precision ? ft_putchar('0', fs->precision, fs) : 0;
	if (fs->len)
		ft_putnbr(fs->l, fs);
	if (fs->minus)
		if (fs->width)
			ft_putchar(' ', fs->width, fs);
}
