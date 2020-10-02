/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:25:09 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 03:46:55 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_c_spec(t_data *d)
{
	char		*s;
	char		c;

	if (!(s = (char*)malloc(2)))
		return (0);
	c = (unsigned char)va_arg(d->args, int);
	s[0] = c;
	s[1] = '\0';
	ARG = s;
	ft_handler_char(d);
	return (0);
}

int		ft_s_spec(t_data *d)
{
	ARG = va_arg(d->args, char*);
	if (!ARG && (PREC > 5 || PREC == -1))
		ARG = ft_strdup("(null)");
	ft_handler_char(d);
	return (0);
}

int		ft_p_conv(t_data *d)
{
	uintmax_t	num;

	num = (uintmax_t)va_arg(d->args, void*);
	ARG = ft_itoa_base2(num, 16);
	if (num == 0)
	{
		free(ARG);
		ARG = ft_strdup("(nil)");
		return (-1);
	}
	return(0);
}

int		ft_p_spec(t_data *d)
{
	int		i;
	char 		*str;
	
	if (ft_p_conv(d) == -1)
	{
		ft_handler_num(d);
		return(0);
	}
	str = ARG;
	if (!(ARG = malloc(ft_strlen(str + 3))))
		return (0);
	ARG[0] = '0';
	ARG[1] = 'x';
	i = -1;
	while (str[++i])
	{
		ARG[i + 2] = str[i];
	}
	ARG[i + 2] = '\0';
	free(str);
	ft_handler_num(d);
	return (0);
}
