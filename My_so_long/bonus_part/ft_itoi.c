/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:06:19 by ouidriss          #+#    #+#             */
/*   Updated: 2023/05/26 13:18:02 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_filled(char *str, int start, int end, int n)
{
	int	i;

	i = 0;
	while (start < end)
	{
		str[end - 1 - i] = 48 + (n % 10);
		n = n / 10;
		start ++;
		i ++;
	}
	str[end] = '\0';
	return (str);
}

int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n < 10)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		i;
	int		start;
	int		size;
	char	*str;

	start = 0;
	i = 0;
	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	if (n < 0)
		size = ft_size(-n) + 1;
	else
		size = ft_size(n);
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		start = 1;
	}
	ft_filled(str, start, size, n);
	return (str);
}
