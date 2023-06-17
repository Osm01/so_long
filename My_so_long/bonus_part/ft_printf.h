/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:39:48 by ouidriss          #+#    #+#             */
/*   Updated: 2023/05/25 21:50:42 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_putnbr_unsigned(unsigned int n, int *counter);
void	ft_convert_hex(size_t n, int *counter, int is_upper_case);

#endif