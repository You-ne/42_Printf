/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:45:12 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 10:49:01 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_dig(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n + 87);
}

char	*hex_conv(unsigned int u, int step)
{
	static char *hex;
	static int	l;
	int			i;

	if (!step)
	{
		hex = (char *)malloc(17);
		i = 0;
		while (i < 17)
			hex[i++] = 0;
		l = 0;
	}
	if (u / 16)
		hex_conv(u / 16, 1);
	hex[l++] = hex_dig(u % 16);
	return (hex);
}

void	convert_big_x(t_fs *fs)
{
	int i;

	i = 0;
	while (fs->s[i])
	{
		if (fs->s[i] >= 'a' && fs->s[i] <= 'z')
			fs->s[i] -= 32;
		i++;
	}
}

void	correct_hex(t_fs *fs)
{
	fs->s = hex_conv(fs->u, 0);
	if (fs->spec == 'X')
		convert_big_x(fs);
	fs->len = len(fs->s);
	if (!fs->u && fs->point && fs->precision == 0)
		fs->len = 0;
	fs->precision -= (fs->precision > fs->len) ? fs->len : fs->precision;
	fs->width -= (fs->width > fs->precision + fs->len) ? \
	fs->precision + fs->len : fs->width;
}

void	print_hex(t_fs *fs)
{
	if (!fs->minus)
		if (fs->width)
			fs->zero ? ft_putchar('0', fs->width, fs) : \
			ft_putchar(' ', fs->width, fs);
	fs->precision ? ft_putchar('0', fs->precision, fs) : 0;
	if (fs->len)
		ft_putstr(fs->s, fs);
	if (fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
	free(fs->s);
}
