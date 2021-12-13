/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:14:29 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/29 14:10:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap);
int	ft_print_percent(void);
int	ft_print_string(va_list ap);
int	ft_print_int(int i);
int	ft_print_u(unsigned int i);
int	ft_print_x(unsigned int i);
int	ft_print_xx(unsigned int i);
int	ft_print_0x(unsigned long long i);

int	ft_specifier(char s, va_list ap)
{
	int	len_spec;

	len_spec = 0;
	if (s == 'c')
		len_spec += ft_print_char(ap);
	else if (s == '%')
		len_spec += ft_print_percent();
	else if (s == 's')
		len_spec += ft_print_string(ap);
	else if (s == 'i' || s == 'd')
		len_spec += ft_print_int(va_arg(ap, int));
	else if (s == 'u')
		len_spec += ft_print_u(va_arg(ap, unsigned int));
	else if (s == 'x')
		len_spec += ft_print_x(va_arg(ap, unsigned int));
	else if (s == 'X')
		len_spec += ft_print_xx(va_arg(ap, unsigned int));
	else if (s == 'p')
		len_spec += ft_print_0x(va_arg(ap, unsigned long long));
	return (len_spec);
}
