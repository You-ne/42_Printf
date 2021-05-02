/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:18:45 by yotillar          #+#    #+#             */
/*   Updated: 2021/01/20 22:12:38 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_check_flags(t_data *d)
{
	while (d->ft[d->fi] == '0' || d->ft[d->fi] == '-')
	{
		if (d->ft[d->fi] == '0')
			d->f[0] = 1;
		if (d->ft[d->fi] == '-')
			d->f[1] = 1;
		d->fi++;
	}
}

void			ft_check_width(t_data *d)
{
	int			i;
	char		*str;

	i = d->fi;
	if (d->ft[d->fi] == '*')
	{
		d->f[2] = va_arg(d->va, int);
		d->fi++;
		if (d->f[2] < 0)
			d->f[1] = 1;
		if (d->f[2] < 0)
			d->f[2] *= -1;
	}
	else
	{
		while (ft_isdigit(d->ft[d->fi]))
			d->fi++;
		if (d->fi - i > 0)
		{
			str = ft_substr(d->ft, i, d->fi - i);
			d->f[2] = ft_atoi(str);
			free(str);
		}
	}
	(d->ft[d->fi] == '-') ? (d->f[1] = 1) : 0;
}

void			ft_check_prec(t_data *d)
{
	int			i;
	char		*str;

	if (d->ft[d->fi] == '.')
	{
		i = ++d->fi;
		d->f[3] = 0;
		while (ft_isdigit(d->ft[d->fi]))
			d->fi++;
		if (d->fi - i > 0)
		{
			str = ft_substr(d->ft, i, d->fi - i);
			d->f[3] = ft_atoi(str);
			free(str);
		}
		if (d->ft[d->fi] == '*' && d->fi == i)
		{
			d->f[3] = va_arg(d->va, int);
			if (d->f[3] < -1)
				d->f[3] = -1;
			d->fi++;
		}
	}
}

int				ft_check(t_data *d)
{
	ft_check_initialize(d);
	if (d->ft[d->fi] == '-' || d->ft[d->fi] == '0' || d->ft[d->fi] == '*' ||
		d->ft[d->fi] == '.' || ft_isdigit(d->ft[d->fi]))
	{
		ft_check_flags(d);
		ft_check_width(d);
		ft_check_prec(d);
	}
	if (d->fi == (int)ft_strlen(d->ft) ||
		(d->ft[d->fi] != 'd' && d->ft[d->fi] != 'i' && d->ft[d->fi] != 'u' &&
		d->ft[d->fi] != 'c' && d->ft[d->fi] != 's' && d->ft[d->fi] != 'p' &&
		d->ft[d->fi] != 'x' && d->ft[d->fi] != 'X' && d->ft[d->fi] != '%'))
		return (-1);
	return (0);
}
