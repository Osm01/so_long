/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:31:42 by ouidriss          #+#    #+#             */
/*   Updated: 2022/12/12 15:55:57 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static void	after_percent(char character, va_list v_list, int *counter)
{
	if (character == 'c')
		ft_putchar(va_arg(v_list, int), counter);
	if (character == 's')
		ft_putstr(va_arg(v_list, char *), counter);
	if (character == 'd' || character == 'i')
		ft_putnbr(va_arg(v_list, int), counter);
	if (character == 'u')
		ft_putnbr_unsigned(va_arg(v_list, unsigned int), counter);
	if (character == '%')
		ft_putchar('%', counter);
	if (character == 'X')
		ft_convert_hex(va_arg(v_list, unsigned int), counter, 1);
	if (character == 'x')
		ft_convert_hex(va_arg(v_list, unsigned int), counter, 0);
	if (character == 'p')
	{
		ft_putstr("0x", counter);
		ft_convert_hex(va_arg(v_list, size_t), counter, 0);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	v_list;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(v_list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			after_percent(str[i + 1], v_list, &counter);
			i ++;
		}
		else
			ft_putchar(str[i], &counter);
		i ++;
	}
	va_end(v_list);
	return (counter);
}
