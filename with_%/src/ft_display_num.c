/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:51:19 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/14 03:25:55 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_num_width2(t_data *d, size_t len)
{
	size_t		i;

	i = 0;
	if (d->f[1] == 1)
		ft_num_minus(d, len);
	else if (d->f[0] == 1 && d->f[3] < 0)
		ft_num_zero(d, len);
	else
	{
		d->f[3] += (d->s[0] == '-' ? 1 : 0);
		while (d->f[2]-- > ft_max(d->f[3], len))
			ft_buffing(' ', d);
		ft_sign(d, &i);
		while (d->f[3]-- > (int)len)
			ft_buffing('0', d);
		while (i < len)
			ft_buffing(d->s[i++], d);
	}
}

void		ft_num_width(t_data *d)
{
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	if ((d->f[3] >= 0 || d->f[3] == -1) && !(d->f[3] == 0 && d->zero == 1))
		len = ft_strlen(d->s);
	if (d->spe == 'p' && d->f[3] == 0 && d->zero == 1)
		len = 2;
	if ((int)len < d->f[2])
		ft_num_width2(d, len);
	else
	{
		ft_sign(d, &i);
		while (i < len && !(d->zero == 1 && d->f[3] == 0))
			ft_buffing(d->s[i++], d);
	}
}

void		ft_num_only_prec(t_data *d)
{
	size_t		i;
	size_t		len;
	int			len_pad;

	i = 0;
	len = (ft_strlen(d->s) - (d->s[0] == '-' ? 1 : 0));
	len_pad = d->f[3] - len;
	if (d->s[0] == '-')
		ft_sign(d, &i);
	while (len_pad > 0 && len_pad-- > 0)
		ft_buffing('0', d);
	while (len-- > 0)
		ft_buffing(d->s[i++], d);
}

void		ft_num_zero(t_data *d, size_t len)
{
	size_t		i;
	size_t		len_pad;

	i = 0;
	len_pad = d->f[2] - len;
	if (d->s[0] == '-')
		len--;
	len_pad -= ft_sign(d, &i);
	while (len_pad-- > 0)
		ft_buffing('0', d);
	while (len-- > 0)
		ft_buffing(d->s[i++], d);
}

void		ft_num_minus(t_data *d, size_t len)
{
	size_t		i;
	size_t		len_pad;

	i = 0;
	d->f[3] += (((ft_sign(d, &i) == 0) && d->s[0] == '-') ? 1 : 0);
	len_pad = d->f[2] - ft_max(d->f[3], len);
	while (d->f[3]-- > (int)len)
		ft_buffing('0', d);
	while (i < len)
		ft_buffing(d->s[i++], d);
	while (len_pad != 0 && len_pad-- > 0)
		ft_buffing(' ', d);
}
