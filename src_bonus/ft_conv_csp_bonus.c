/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_csp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:25:09 by yotillar          #+#    #+#             */
/*   Updated: 2021/01/20 21:56:41 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

int				ft_c_spec(t_data *d)
{
	char		*s;
	char		c;

	if (!(s = (char*)malloc(2)))
		return (0);
	c = (unsigned char)va_arg(d->va, int);
	s[0] = c;
	s[1] = '\0';
	d->s = s;
	ft_handler_char(d);
	return (0);
}

int				ft_s_spec(t_data *d)
{
	d->s = va_arg(d->va, char*);
	if (!d->s)
		d->s = ft_strdup("(null)");
	ft_handler_char(d);
	return (0);
}

int				ft_p_conv(t_data *d)
{
	uintmax_t	num;

	num = (uintmax_t)va_arg(d->va, void*);
	d->s = ft_itoa_base(num, "0123456789abcdef");
	return (0);
}

int				ft_p_spec(t_data *d)
{
	int			i;
	char		*str;

	str = d->s;
	if (!(d->s = malloc(ft_strlen(str + 3))))
		return (0);
	d->s[0] = '0';
	d->s[1] = 'x';
	i = -1;
	while (str[++i])
	{
		d->s[i + 2] = str[i];
	}
	d->s[i + 2] = '\0';
	free(str);
	ft_handler_num(d);
	return (0);
}
