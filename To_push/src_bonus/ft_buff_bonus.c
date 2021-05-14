/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:02:53 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 19:03:50 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

void	ft_buffing(char c, t_data *d)
{
	d->buff[d->bi] = c;
	d->bi++;
	if (d->bi == 127)
	{
		write(1, &d->buff, 127);
		d->ret += 127;
		while (d->bi > 0)
		{
			d->buff[d->bi] = '\0';
			d->bi--;
		}
	}
}
