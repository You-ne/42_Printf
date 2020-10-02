/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 06:01:21 by yotillar          #+#    #+#             */
/*   Updated: 2020/09/30 06:01:58 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

uintmax_t		conv_ex(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(uintmax_t value, uintmax_t base, int neg)
{
	int			i;
	char			*str;
	uintmax_t		tmp;

	i = 0;
	tmp = value;
	if (neg > 0)
		i += 1;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0 && neg == 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	while (i > 0 && neg == 1)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa_base2(uintmax_t value, uintmax_t base)
{
	int			i;
	char			*str;
	uintmax_t		tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned int		res;
	int					sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return ((int)res * sign);
}
