/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:42 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/12 18:03:15 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	part_two(t_points p0, t_points p1, t_fdf_vars *fdf, \
			t_bresenham_vars line);
static int	color_shift(t_points p0, t_points p1, t_bresenham_vars line);
static void	plot_line(t_points p0, t_points p1, int nbr_pix, t_fdf_vars *fdf);

void	bham(t_points p0, t_points p1, t_fdf_vars *fdf)
{
	t_bresenham_vars	line;

	line.dx = abs(p1.x - p0.x);
	line.dy = -abs(p1.y - p0.y);
	line.err = line.dx + line.dy;
	if (p0.x < p1.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (p0.y < p1.y)
		line.sy = 1;
	else
		line.sy = -1;
	part_two(p0, p1, fdf, line);
}

/* part two from bham splitted for norm reasons */
static void	part_two(t_points p0, t_points p1, t_fdf_vars *fdf, \
			t_bresenham_vars line)
{
	int	nbr_pix;

	nbr_pix = color_shift(p0, p1, line);
	if (nbr_pix == 0)
		nbr_pix = 1;
	fdf->i = nbr_pix;
	fdf->j = 0;
	while (1)
	{
		plot_line(p0, p1, nbr_pix, fdf);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > line.dy)
		{
			line.err += line.dy;
			p0.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			p0.y += line.sy;
		}
	}
}

/* counts pixel between two given points with bresenham algorithm*/
static int	color_shift(t_points p0, t_points p1, t_bresenham_vars line)
{
	int	nbr_pix;

	nbr_pix = 0;
	while (1)
	{
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 > line.dy)
		{
			line.err += line.dy;
			p0.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			p0.y += line.sy;
		}
		nbr_pix++;
	}
	return (nbr_pix);
}

/* uses subfct pixel_put if pixel is in frame */
static void	plot_line(t_points p0, t_points p1, int nbr_pix, t_fdf_vars *fdf)
{
	if (check_in_frame(p0) == 0)
	{
		if (p0.color != p1.color)
		{
			pixel_put(fdf, p0.x, p0.y, (((p0.color * fdf->i) + \
					(p1.color * fdf->j)) / nbr_pix));
			fdf->i--;
			fdf->j++;
		}
		else
			pixel_put(fdf, p0.x, p0.y, p0.color);
	}
}
