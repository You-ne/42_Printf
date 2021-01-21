/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:35:00 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 19:07:49 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

int		ft_hash(t_data *d)
{
	if (d->spe == 'o')
	{
		if (d->s[0] != '0')
		{
			ft_buffing('0', d);
			return (1);
		}
	}
	if (d->spe == 'x')
	{
		ft_buffing('0', d);
		ft_buffing('x', d);
		return (2);
	}
	if (d->spe == 'X')
	{
		ft_buffing('0', d);
		ft_buffing('X', d);
		return (2);
	}
	return (0);
}

int		ft_sign(t_data *d, size_t *i)
{
	if (d->s[0] == '-')
	{
		ft_buffing('-', d);
		*i += 1;
	}
	else if (d->f[4] == 1)
	{
		ft_buffing('+', d);
		return (1);
	}
	else if (d->f[5] == 1)
	{
		ft_buffing(' ', d);
		return (1);
	}
	return (0);
}

void	ft_display(t_data *d)
{
	write(1, &d->buff, d->bi);
	d->ret += d->bi;
	d->bi = 0;
}
