/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:50 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/11 15:06:28 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_fdf_vars *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->size_line + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_scale(t_fdf_vars *fdf)
{
	int	ratio;

	if (fdf->width > fdf->height)
		ratio = (WIDTH - FRAME) / fdf->width;
	else
		ratio = (HEIGHT - FRAME) / fdf->height;
	if (ratio < 2)
		fdf->scale = 2;
	if (ratio > 35)
		fdf->scale = 35;
	else
		fdf->scale = ratio;
}

int	check_in_frame(t_points p)
{
	if ((p.x <= WIDTH - FRAME) && (p.y <= HEIGHT - FRAME) \
		&& (p.x >= FRAME) && (p.y >= FRAME))
		return (0);
	else
		return (1);
}

void	center(t_fdf_vars *fdf, int row, int col)
{
	fdf->p_p[row][col].x = fdf->p_p[row][col].x + (WIDTH / 2) \
		+ fdf->x_center;
	fdf->p_p[row][col].y = fdf->p_p[row][col].y + (HEIGHT / 2) \
		+ fdf->y_center;
}
