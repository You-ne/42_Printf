/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:41:31 by yotillar          #+#    #+#             */
/*   Updated: 2021/01/20 21:58:37 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_char_minus(t_data *d, size_t len)
{
	int	i;

	i = 0;
	if (d->spe == 'c')
	{
		ft_buffing(d->s[i++], d);
		d->f[2]--;
	}
	if (d->spe == 's')
	{
		while (i < (int)len && d->s && d->s[i] != '\0')
		{
			ft_buffing(d->s[i++], d);
			d->f[2]--;
		}
	}
	while (d->f[2]-- > 0)
		ft_buffing(' ', d);
}

void	ft_char_width(t_data *d, size_t len)
{
	int	i;

	i = 0;
	if (d->f[1] == 1)
		ft_char_minus(d, len);
	else
	{
		while (d->f[2]-- > (int)len)
			ft_buffing(' ', d);
		while (len-- > 0 && d->s)
			ft_buffing(d->s[i++], d);
	}
}
