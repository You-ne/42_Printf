/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:29:41 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/14 03:17:14 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_handler_char(t_data *d)
{
	int		i;
	size_t	len;

	i = 0;
	if (d->spe == 'c')
		len = 1;
	else if (d->f[3] >= 0)
		len = ft_min(ft_strlen(d->s), d->f[3]);
	else
		len = ft_strlen(d->s);
	if (d->f[2] > (int)len)
		ft_char_width(d, len);
	else
	{
		if (d->spe == 'c' && d->s && d->s[0] == '\0')
		{
			ft_display(d);
			write(1, d->s, 1);
			d->ret += 1;
		}
		while (i < (int)len && !(d->spe == 'c' && d->s && d->s[0] == '\0'))
			ft_buffing(d->s[i++], d);
	}
	ft_end(d);
}

void		ft_handler_num(t_data *d)
{
	size_t		i;

	i = -1;
	if (d->f[3] > 0 && d->f[3] >= d->f[2])
		ft_num_only_prec(d);
	else if (d->f[2] > 0)
		ft_num_width(d);
	else
	{
		ft_sign(d, &i);
		while (d->s[++i] != '\0' && d->f[2] == 0 && d->f[3] <= 0
			&& !(d->f[3] == 0 && d->zero == 1))
			ft_buffing(d->s[i], d);
		if (d->spe = 'p' && d->zero == 1 && d->f[3] == 0)
		{
			ft_buffing('0', d);
			ft_buffing('x', d);
		}
	}
	d->zero = 0;
	ft_end(d);
}
