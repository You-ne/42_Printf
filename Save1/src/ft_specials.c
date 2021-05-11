/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:35:00 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 22:37:22 by yotillar         ###   ########.fr       */
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
	d->bi = 0;
}
