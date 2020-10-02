/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_du.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:11:48 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 03:19:58 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_d_spec(t_data *d)
{

	intmax_t	arg;
	int		neg;

	neg = 0;
	arg = 0;
	if (d->spe == 'd' || d->spe == 'i')
		arg = (intmax_t)(va_arg(d->args, int));
	if (arg < 0)
	{
		neg = 1;
		arg *= -1;
	}
	ARG = ft_itoa_base(arg, 10, neg);
	ft_handler_num(d);
	return (0);
}

int		ft_u_spec(t_data *d)
{
	unsigned int arg;

	arg = 0;
	if (d->spe =='u')
		arg = (unsigned int)(va_arg(d->args, unsigned int));
	ARG = ft_itoa_base(arg, 10, 0);
	ft_handler_num(d);
	return (0);
}

int	ft_x_spec(t_data *d)
{
	int 	i;
	unsigned int	arg;

	arg = 0;
	if (d->spe == 'x' || d->spe == 'X')
		arg = (unsigned int)va_arg(d->args, unsigned int);
	ARG = ft_itoa_base2(arg, 16);
	if (d->spe == 'X')
	{
		i = -1;
		while (ARG[++i])
			if (ARG[i] > 96 && ARG[i] < 123)
				ARG[i] -= 32;
	}
	ft_handler_num(d);
	return (0);
}
