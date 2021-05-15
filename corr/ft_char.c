/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:50:18 by edjavid           #+#    #+#             */
/*   Updated: 2021/05/13 10:50:19 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_fs *fs)
{
	if (fs->width)
		fs->width--;
	if (!fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
	ft_putchar(fs->c, 1, fs);
	if (fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
}

void	correct_str(t_fs *fs)
{
	fs->len = fs->s != NULL ? len(fs->s) : 6;
	fs->len = (fs->point && fs->len > fs->precision) ? fs->precision : fs->len;
	fs->width -= (fs->width > fs->len) ? fs->len : fs->width;
}

void	print_str(t_fs *fs)
{
	if (!fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
	if (fs->s != NULL)
		ft_putstr(fs->s, fs);
	if (fs->s == NULL)
		ft_putstr("(null)", fs);
	if (fs->minus)
		fs->width ? ft_putchar(' ', fs->width, fs) : 0;
}
