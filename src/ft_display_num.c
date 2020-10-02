/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:51:19 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 22:35:44 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_num_width2(t_data *d, size_t len)//hashed
{
	size_t		i;

	i = 0;
	if (MINUS == 1)
			ft_num_minus(d, len);
		else if (ZERO == 1 && PREC < 0)
			ft_num_zero(d, len);
		else
		{
			PREC += (ARG[0] == '-' ? 1 : 0);
			WIDTH -= ((ARG[0] != '-' && (PLUS == 1 || SPACE == 1)) ? 1 : 0);
			WIDTH -= (((d->spe =='x' || d->spe == 'X') && HASH == 1) ? 2 : 0);
			while (WIDTH-- > ft_max(PREC,len))
				ft_buffing(' ', d);
			ft_sign(d, &i);
			HASH == 1 ? ft_hash(d) : 0;
			PREC -= ((d->spe == 'o' && ARG[0] != '0' && HASH == 1) ? 1 : 0);
			while (PREC-- > (int)len)
				ft_buffing('0', d);
			while (i < len)
				ft_buffing(ARG[i++], d);
		}
}

void		ft_num_width(t_data *d)//hashed
{
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	if (PREC > 0 || PREC == -1)
		len = ft_strlen(ARG);
	if ((int)len < WIDTH)
		ft_num_width2(d, len);
	else
	{
		ft_sign(d, &i);
		HASH == 1 ? ft_hash(d) : 0;
		while (i < len)
			ft_buffing(ARG[i++], d);
	}
}

void		ft_num_only_prec(t_data *d)//hashed
{
	size_t	i;
	size_t	len;
	int		len_pad;

	i = 0;
	len = (ft_strlen(ARG) - (ARG[0] == '-' ? 1 : 0));
	len_pad = PREC - len;
	if (SPACE == 1 || PLUS == 1 || ARG[0] == '-')
		ft_sign(d, &i);
	HASH == 1 ? ft_hash(d) : 0;
	if (d->spe == 'o' && HASH == 1 && ARG[0] != '0')
		len_pad -= 1;
	while (len_pad > 0 && len_pad-- > 0)
		ft_buffing('0', d);
	while (len-- > 0)
		ft_buffing(ARG[i++], d);
}

void		ft_num_zero(t_data *d, size_t len) //hashed
{
	size_t	i;
	size_t	len_pad;

	i = 0;
	len_pad = WIDTH - len;
	if (ARG[0] == '-')
		len--;
	len_pad -= (ft_sign(d, &i) + (HASH == 1 ? ft_hash(d) : 0));
	while (len_pad-- > 0)
		ft_buffing('0', d);
	while (len-- > 0)
		ft_buffing(ARG[i++], d);
}

void		ft_num_minus(t_data *d, size_t len)
{
	size_t	i;
	size_t	len_pad;

	i = 0;
	PREC += (((ft_sign(d, &i) == 0) && ARG[0] == '-') ? 1 : 0);
	len_pad = WIDTH - ft_max(PREC, len);
	PREC -= ((d->spe == 'o' && HASH == 1) ? 1 : 0);
	HASH == 1 ? ft_hash(d) : 0;
	if (ARG[0] != '-' && (SPACE == 1 || PLUS == 1))
		len_pad -= 1;
	if ((d->spe == 'X' || d->spe == 'x') && (HASH == 1))
		len_pad -= 2;
	while (PREC-- > (int)len)
		ft_buffing('0',d);
	while (i < len)
		ft_buffing(ARG[i++], d);
	while (len_pad != 0 && len_pad-- > 0)
		ft_buffing(' ', d);
}
