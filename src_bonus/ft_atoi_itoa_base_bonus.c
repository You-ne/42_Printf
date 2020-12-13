/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa_base_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:08:01 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/24 19:04:17 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

int					ft_nlen_itoa_base(long nbr, int len)
{
	int				i;
	long			x;

	i = 0;
	x = nbr;
	if (x < 0)
		x = -x;
	while (x >= len)
	{
		i++;
		x = x / len;
	}
	i++;
	if (nbr < 0)
		i++;
	return (i);
}

char				*ft_itoa_base(long nbr, char *base)
{
	long			w;
	int				len;
	int				nlen;
	int				neg;
	char			*dest;

	neg = nbr < 0 ? 1 : 0;
	len = (int)ft_strlen(base);
	nlen = ft_nlen_itoa_base(nbr, len);
	dest = malloc(sizeof(char) * nlen + 1);
	dest[nlen] = '\0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		dest[0] = '-';
	}
	while (nlen > neg)
	{
		w = (nbr % len);
		dest[nlen - 1] = base[w];
		nbr = nbr / len;
		nlen--;
	}
	return (dest);
}

int					ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	int				sign;

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
