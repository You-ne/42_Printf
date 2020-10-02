/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <yotillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:20:08 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/01 22:31:53 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./inc/ft_printf.h"
int	main(void)
{
	int	ret;

	ret = 0;


	printf("\n\n///Mon Printf///\n");
	ret = ft_printf("%#-20.10X\n", 420);
	printf("Ret: %d\n\n", ret);
	ret = ft_printf("%#-20.10o\n", 420);
	printf("Ret: %d\n\n", ret);
	printf("///Vrai Printf///\n");
	ret = printf("%#-20.10X\n", 420);
	printf("Ret: %d\n\n", ret);
	ret = printf("%#-20.10o\n", 420);
	printf("Ret: %d\n\n", ret);
	return (0);
}
