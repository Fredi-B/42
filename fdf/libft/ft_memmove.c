/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:14:42 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 13:32:35 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_points
{
	int	x;
	int	y;
	int	z;
}				t_points;

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_points	*u_src;
	t_points	*u_dst;
	size_t		i;

	u_src = (t_points *)src;
	u_dst = (t_points *)dst;
	if (!dst && !src)
		return (0);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			u_dst[i] = u_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
			u_dst[len] = u_src[len];
	}
	return (dst);
}
