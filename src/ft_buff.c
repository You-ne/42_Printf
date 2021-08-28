/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:02:53 by yotillar          #+#    #+#             */
/*   Updated: 2021/05/14 02:55:56 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_buffing(char c, t_data *d)
{
	d->buff[d->bi] = c;
	d->bi++;
	if (d->bi == 127)
		ft_display(d);
}