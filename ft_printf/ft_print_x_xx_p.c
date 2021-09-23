/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_xx_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:14:02 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/29 11:08:14 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int i)
{
	int		len_spec;
	char	*hex;

	len_spec = 0;
	hex = "0123456789abcdef";
	if (i >= 16)
		len_spec += ft_print_x(i / 16);
	ft_putchar_fd(hex[i % 16], 1);
	len_spec += 1;
	return (len_spec);
}

int	ft_print_xx(unsigned int i)
{
	int		len_spec;
	char	*hexx;

	hexx = "0123456789ABCDEF";
	len_spec = 0;
	if (i >= 16)
		len_spec += ft_print_xx(i / 16);
	ft_putchar_fd(hexx[i % 16], 1);
	len_spec += 1;
	return (len_spec);
}

int	ft_print_p(unsigned long long i)
{
	char	*p;
	int		len_spec;

	p = "0123456789abcdef";
	len_spec = 0;
	if (i >= 16)
		len_spec += ft_print_p(i / 16);
	ft_putchar_fd(p[i % 16], 1);
	len_spec += 1;
	return (len_spec);
}

int	ft_print_0x(unsigned long long i)
{
	int	len_spec;

	len_spec = 2;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len_spec += ft_print_p(i);
	return (len_spec);
}
