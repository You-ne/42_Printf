/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:11:48 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/11 00:06:34 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_d_spec(t_data *d)
{
	intmax_t		arg;

	arg = 0;
	if (d->spe == 'd' || d->spe == 'i')
		arg = (intmax_t)(va_arg(d->va, int));
	if (arg == 0)
		d->zero = 1;
	d->s = ft_itoa_base(arg, "0123456789");
	ft_handler_num(d);
	return (0);
}

int					ft_u_spec(t_data *d)
{
	unsigned int	arg;

	arg = 0;
	if (d->spe == 'u')
		arg = (unsigned int)(va_arg(d->va, unsigned int));
	if (arg == 0)
		d->zero = 1;
	d->s = ft_itoa_base(arg, "0123456789");
	ft_handler_num(d);
	return (0);
}

int					ft_x_spec(t_data *d)
{
	int				i;
	unsigned int	arg;

	arg = 0;
	if (d->spe == 'x' || d->spe == 'X')
		arg = (unsigned int)va_arg(d->va, unsigned int);
	if (arg == 0)
		d->zero = 1;
	d->s = ft_itoa_base(arg, "0123456789abcdef");
	if (d->spe == 'X')
	{
		i = -1;
		while (d->s[++i])
			if (d->s[i] > 96 && d->s[i] < 123)
				d->s[i] -= 32;
	}
	ft_handler_num(d);
	return (0);
}
