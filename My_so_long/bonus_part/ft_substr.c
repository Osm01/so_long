/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:39:36 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/01 18:11:55 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlenn(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strdupp(const char *s1)
{
	size_t	i;
	size_t	ln;
	char	*str;

	i = 0;
	ln = ft_strlenn(s1);
	if (!s1)
		return (0);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		*(str + i) = *(char *)(s1 + i);
		i ++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_substrr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (start >= ft_strlenn(s))
		return (ft_strdupp(""));
	if (len > ft_strlenn(s))
		len = ft_strlenn(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len && s[i] != '\0')
	{
		*(char *)(sub + i) = *(char *)(s + start);
		i ++;
		start ++;
	}
	*(char *)(sub + i) = '\0';
	return (sub);
}
