/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:41:31 by yotillar          #+#    #+#             */
/*   Updated: 2020/09/30 05:22:55 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_char_minus(t_data *d, size_t len)
{
	int	i;

	i = 0;
	if (d->spe == 'c')
	{
		ft_buffing(ARG[i++], d);
		WIDTH--;
	}
	if (d->spe == 's')
	{
		while (i < (int)len && ARG && ARG[i] != '\0')
		{
			ft_buffing(ARG[i++], d);
			WIDTH--;
		}
	}
	while (WIDTH-- > 0)
		ft_buffing(' ', d);
}

void	ft_char_width(t_data *d, size_t len)
{
	int	i;

	i = 0;
	if (!ARG && (PREC > 5 || PREC == -1))
		len = 6;
	if (MINUS == 1)
		ft_char_minus(d, len);
	else
	{
		while (WIDTH-- > (int)len)
			ft_buffing(' ', d);
		while (len-- > 0 && ARG)
			ft_buffing(ARG[i++], d);
	}
}
