/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:27 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 13:50:38 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf_vars *fdf)
{
	if (key == ESC_K)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_points(fdf, fdf->height);
		exit (0);
	}
	return (0);
}
