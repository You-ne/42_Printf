/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:38:50 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 11:38:51 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ulen(unsigned long long n)
{
	int l;

	l = 1;
	while (n > 9)
	{
		n /= 10;
		l++;
	}
	return (l);
}

void	correct_u(t_fs *fs)
{
	fs->len = ulen(fs->u);
	if (fs->u == 0 && fs->point)
		fs->len = 0;
	fs->precision -= (fs->precision > fs->len) ? fs->len : fs->precision;
	fs->width -= (fs->width > fs->precision + fs->len) ? \
	fs->precision + fs->len : fs->width;
}

void	print_u(t_fs *fs)
{
	if (!fs->minus)
	{
		if (fs->width)
			fs->zero ? ft_putchar('0', fs->width, fs) : \
			ft_putchar(' ', fs->width, fs);
	}
	fs->precision ? ft_putchar('0', fs->precision, fs) : 0;
	if (fs->point && fs->u == 0 && fs->len && fs->precision == 0)
		return ;
	if (fs->len)
		ft_putnbr(fs->u, fs);
	if (fs->minus)
		if (fs->width)
			ft_putchar(' ', fs->width, fs);
}
