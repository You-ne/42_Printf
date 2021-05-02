/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:52:44 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 18:54:59 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

void	ft_check_initialize(t_data *d)
{
	d->fi = 0;
	while (d->fi < NB_FLAGS)
	{
		d->f[d->fi] = 0;
		d->fi++;
	}
	d->f[3] = -1;
	d->fi = 0;
}

void	ft_init(t_data *d)
{
	d->bi = 0;
	while (d->bi < 128)
	{
		d->buff[d->bi] = '\0';
		d->bi++;
	}
	d->bi = 0;
	d->fi = 0;
	d->spe = '\0';
	d->ret = 0;
	d->s = NULL;
	d->ft = NULL;
	return ;
}
