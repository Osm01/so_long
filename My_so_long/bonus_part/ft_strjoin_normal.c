/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:14:32 by ouidriss          #+#    #+#             */
/*   Updated: 2023/05/26 13:18:08 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

unsigned long	ln(char const *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strjoin_normal(char const *s1, char const *s2)
{
	char			*join;
	unsigned long	ln_s1;
	unsigned long	ln_s2;
	unsigned long	i;
	unsigned long	index;

	i = 0;
	index = 0;
	ln_s1 = ln(s1);
	ln_s2 = ln(s2);
	join = malloc(sizeof(char) * (ln_s1 + ln_s2 + 1));
	if (join == NULL)
		return (0);
	while (index < ln_s1)
	{
		*(join + i++) = *(char *)(s1 + index++);
	}
	index = 0;
	while (index < ln_s2)
	{
		*(join + i++) = *(char *)(s2 + index++);
	}
	*(join + i) = '\0';
	return (join);
}
