/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:24:31 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:52 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *counter)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48, counter);
	else if (n < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-n, counter);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}
