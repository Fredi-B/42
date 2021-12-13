/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:48:46 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/29 11:29:29 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_pow(int len)
{
	int	x;

	x = 1;
	while (len)
	{
		x *= 10;
		len--;
	}
	return (x);
}

static int	n_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*strfill(char *s, int len, int n, int i)
{
	while (len)
	{
		s[i] = n / my_pow(len - 1) + '0';
		n %= my_pow(len - 1);
		i++;
		len--;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 || n == -0)
	{
		s = (char *)malloc(n_len(n) + 1 + 1);
		if (!s)
			return (0);
		s[0] = '-';
		if (n == 0)
			s[0] = '0';
		n *= -1;
		i = 1;
	}
	else
	{
		s = (char *)malloc(n_len(n) + 1);
		if (!s)
			return (0);
		i = 0;
	}
	return (strfill(s, n_len(n), n, i));
}

int	ft_print_int(int i)
{
	char	*str;
	int		len_spec;
	int		j;

	str = ft_itoa(i);
	len_spec = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		len_spec += 1;
		j++;
	}
	free(str);
	return (len_spec);
}
