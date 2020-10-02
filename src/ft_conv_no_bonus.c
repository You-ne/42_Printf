/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_no_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:09:54 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 22:47:47 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_o_spec(t_data *d)
{
	unsigned int	arg;

	arg = 0;
	if (d->spe == 'o')
		arg = (unsigned int)va_arg(d->args, unsigned int);
	ARG = ft_itoa_base2(arg, 8);
	ft_handler_num(d);
	return (0);
}

int		ft_n_spec(t_data *d)
{
	int		*num_chars;

	num_chars = (int*)va_arg(d->args, int*);
	*num_chars = d->bi + d->ret;
	return (0);
}
