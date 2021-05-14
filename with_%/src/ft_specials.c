/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:35:00 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/14 02:54:29 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_sign(t_data *d, size_t *i)
{
	if (d->s[0] == '-')
	{
		ft_buffing('-', d);
		*i += 1;
	}
	return (0);
}

void	ft_display(t_data *d)
{
	write(1, &d->buff, d->bi);
	d->ret += d->bi;
	while (d->bi > 0)
	{
		d->buff[d->bi] = '\0';
		d->bi--;
	}
	d->buff[d->bi] = '\0';
}

void	ft_pct2(t_data *d)
{
	if (d->f[1] != 0)
	{
		ft_buffing('%', d);
		while (d->f[2] > 1)
		{
			ft_buffing(' ', d);
			d->f[2] -= 1;
		}
	}
	else
	{
		while (d->f[2] > 1)
		{
			if (d->f[0])
				ft_buffing('0', d);
			else
				ft_buffing(' ', d);
			d->f[2] -= 1;
		}
		ft_buffing('%', d);
	}
}

int		ft_pct(t_data *d)
{
	if (d->f[2] > 1)
		ft_pct2(d);
	else
		ft_buffing('%', d);
	return (0);
}
