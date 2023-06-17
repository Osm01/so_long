/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:23:48 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:55 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (n >= 0 && n < 10)
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
