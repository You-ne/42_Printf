/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:29:41 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 06:16:32 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_handler_char(t_data *d)
{
	int	i;
	size_t	len;

	i = 0;
	if (d->spe == 'c')
		len = 1;
	else if (PREC >= 0)
		len = ft_min(ft_strlen(ARG), PREC);
	else
		len = ft_strlen(ARG);
	if (WIDTH > (int)len)
		ft_char_width(d, len);
	else
	{
		if (d->spe == 'c' && ARG && ARG[0] == '\0')
		{
			ft_display(d);
			write(1, ARG, 1);
		}
		while (i < (int)len && !(d->spe == 'c' && ARG && ARG[0] == '\0'))
			ft_buffing(ARG[i++], d);
	}
	ft_end(d);
}

void		ft_handler_num(t_data *d)
{
	size_t	i;

	i = -1;
	if (PREC > 0 && PREC >= WIDTH)
		ft_num_only_prec(d);
	else if (WIDTH > 0)
		ft_num_width(d);
	else
	{
		ft_sign(d, &i);
		HASH == 1 ? ft_hash(d) : 0;
		while (ARG[++i] != '\0' && WIDTH == 0 && PREC < 0)
			ft_buffing(ARG[i], d);
	}
	ft_end(d);
}
