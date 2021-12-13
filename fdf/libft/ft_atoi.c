/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:39:13 by fbechtol          #+#    #+#             */
/*   Updated: 2021/10/25 16:20:16 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*isspacechar(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return ((str));
}

static const char	*issign(const char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	if (*str == '-' || *str == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	nbr;
	int		sign;

	if (str == NULL)
		return (0);
	str = isspacechar(str);
	str = issign(str, &sign);
	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbr <= 2147483648)
			nbr = nbr * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	if (nbr * sign > 2147483647)
		return (-1);
	if (nbr * sign < -2147483648)
		return (0);
	return (sign * nbr);
}
