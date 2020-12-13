/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_no_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:09:54 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 18:55:56 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

int		ft_o_spec(t_data *d)
{
	unsigned int	arg;

	arg = 0;
	if (d->spe == 'o')
		arg = (unsigned int)va_arg(d->va, unsigned int);
	d->s = ft_itoa_base(arg, "01234567");
	ft_handler_num(d);
	return (0);
}

int		ft_n_spec(t_data *d)
{
	int		*num_chars;

	num_chars = (int*)va_arg(d->va, int*);
	*num_chars = d->bi + d->ret;
	return (0);
}
