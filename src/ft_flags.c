/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:18:45 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 03:38:49 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ft_printf.h"

void	ft_check_flags(t_data *d)
{
	while (FMT[FI] == '0' || FMT[FI] == '-')
	{
		if (FMT[FI] == '0')
			ZERO = 1;
		if (FMT[FI] == '-')
			MINUS = 1;
		FI++;
	}
}


void	ft_check_width(t_data *d)
{

	int		i;
	char	*str;

	i = FI;
	if (FMT[FI] == '*')
	{
		WIDTH = va_arg(d->args, int);
		FI++;
		if (WIDTH < 0)
		{
			MINUS = 1;
			WIDTH *= -1;
		}
	}
	else
	{
		while (ft_isdigit(FMT[FI]))
			FI++;
		if (FI - i > 0)
		{
			str = ft_substr(FMT, i, FI - i);
			WIDTH = ft_atoi(str);
			free(str);
		}
	}		if (FMT[FI] == '-')
				MINUS = 1;
}

void	ft_check_prec(t_data *d)
{
	int		i;
	char	*str;

	if (FMT[FI] == '.')
	{
		i = ++FI;
		PREC = 0;
		while (ft_isdigit(FMT[FI]))
			FI++;
		if (FI - i > 0)
		{
			str = ft_substr(FMT, i, FI - i);
			PREC = ft_atoi(str);
			free(str);
		}
		if (FMT[FI] == '*' && FI == i)
		{
			PREC = va_arg(d->args, int);
			if (PREC < -1)
				PREC = -1;
			FI++;
		}
	}
}

int 	ft_check(t_data *d)
{
	ft_check_initialize(d);
	if (FMT[FI] == '-' || FMT[FI] == '0' || FMT[FI] == '*'|| FMT[FI] == '.'||
		FMT[FI] == ' ' || FMT[FI] == '+' || ft_isdigit(FMT[FI]))
	{
		ft_check_flags(d);
		ft_check_width(d);
		ft_check_prec(d);
	}
	if (FMT[FI] == '%')
	{
		ft_buffing('%', d);
		FI++;
		return (-1);
	}
	if (FI == (int)ft_strlen(FMT) ||
		(FMT[FI] != 'd' && FMT[FI] != 'i' && FMT[FI] != 'u' && FMT[FI] != 'c'
		&& FMT[FI] != 's' && FMT[FI] != 'p' && FMT[FI] != 'x' && FMT[FI] != 'X'))
		return (-1);
	return (0);
}
