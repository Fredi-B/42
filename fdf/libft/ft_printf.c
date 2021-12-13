/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:57:09 by fbechtol          #+#    #+#             */
/*   Updated: 2021/10/13 13:51:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_specifier(*str, ap);
			str++;
		}
		if (*str && *str != '%')
		{
			write(1, &*str, 1);
			len++;
			str++;
		}
	}
	va_end(ap);
	return (len);
}
