/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:07:56 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/28 11:09:32 by fbechtol         ###   ########.fr       */
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

static int	n_len(unsigned int n)
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

static char	*strfill(char *s, int len, unsigned int n, int i)
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

char	*ft_u_itoa(unsigned int n)
{
	char	*s;
	int		i;
	int		len;

	len = 0;
	len = n_len(n);
	{
		if (n == 0)
		{
			s = (char *)malloc(2);
			if (s == NULL)
				return (0);
			s[0] = '0';
			s[1] = '\0';
			return (s);
		}
		s = (char *)malloc(len + 1);
		if (!s)
			return (0);
		if (n == 0)
			s[0] = '0';
		i = 0;
	}
	return (strfill(s, len, n, i));
}

int	ft_print_u(unsigned int i)
{
	char	*str;
	int		len_spec;
	int		j;

	str = ft_u_itoa(i);
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
