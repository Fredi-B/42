/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_p_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:20:16 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/29 11:39:58 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	char	c;
	int		len_spec;

	len_spec = 1;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (len_spec);
}

int	ft_print_percent(void)
{
	char	c;
	int		len_spec;

	len_spec = 1;
	c = '%';
	write(1, &c, 1);
	return (len_spec);
}

int	ft_print_string(va_list ap)
{
	char	*str;
	int		len_spec;
	int		i;

	len_spec = 0;
	str = va_arg(ap, char *);
	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		len_spec += 1;
		i++;
	}
	return (len_spec);
}
