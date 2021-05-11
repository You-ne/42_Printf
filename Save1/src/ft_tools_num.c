/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 05:55:13 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/23 16:28:42 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long		ft_min(long a, long b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

long		ft_max(long a, long b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int			ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
