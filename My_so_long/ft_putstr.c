/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:23:14 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:43 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", counter);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	*counter = *counter + i;
}
