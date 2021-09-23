/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:39:13 by fbechtol          #+#    #+#             */
/*   Updated: 2021/07/21 13:28:17 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	i = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(*dup) * i);
	if (!dup)
		return (0);
	ft_memcpy(dup, s, i);
	return (dup);
}
