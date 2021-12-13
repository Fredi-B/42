/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:49:10 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/15 21:40:49 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		slen;
	int		i;

	slen = ft_strlen(s);
	i = 0;
	while (i <= slen)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
