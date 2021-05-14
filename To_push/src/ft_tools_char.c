/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:02:09 by yotillar          #+#    #+#             */
/*   Updated: 2020/10/23 16:34:21 by yotillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (*s++)
			len++;
	}
	return (len);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(*dest) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	count;
	size_t	size;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	if (!(sub = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		sub[count] = s[start + count];
		count++;
	}
	sub[count] = '\0';
	return (sub);
}
