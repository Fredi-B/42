/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:22 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 13:37:03 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map(t_fdf_vars *fdf);
static void	rotate_scale(t_fdf_vars *fdf, int row, int col);
static void	scale(t_points *p, t_fdf_vars *fdf, int row, int col);

void	draw_map(t_fdf_vars *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	get_scale(fdf);
	map_to_image(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, deal_key, fdf);
	mlx_hook(fdf->win, 17, 0L, close_win, fdf);
	mlx_loop(fdf->mlx);
	return ;
}

void	map_to_image(t_fdf_vars *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
								&fdf->size_line, &fdf->endian);
	get_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return ;
}

/* iterates through all points. Using subfcts to rotate/scale/center 
and draw them */
static void	get_map(t_fdf_vars *fdf)
{
	int	row;
	int	col;

	row = 0;
	while (row < fdf->height)
	{
		col = 0;
		while (col < fdf->width)
		{
			rotate_scale(fdf, row, col);
			if (check_in_frame(fdf->p_p[row][col]) == 0)
			{
				if (row > 0)
					bham(fdf->p_p[row][col], fdf->p_p[row - 1][col], fdf);
				if (col > 0)
					bham(fdf->p_p[row][col], fdf->p_p[row][col - 1], fdf);
			}
			col++;
		}
		row++;
	}
}

/* rotates given point through matrix multiplication.
 Calling subfcts to scale and center it in the window */
static void	rotate_scale(t_fdf_vars *fdf, int row, int col)
{
	double		a;
	double		b;
	double		c;
	t_points	tmp;

	a = fdf->rot_x;
	b = fdf->rot_y;
	c = fdf->rot_z;
	scale(&fdf->points[row][col], fdf, row, col);
	tmp.x = (cos(a) * cos(b) * fdf->p_p[row][col].x);
	tmp.x += (((cos(a) * sin(b) * sin(c)) - (sin(a) * cos(c))) \
				* fdf->p_p[row][col].y);
	tmp.x += (((cos(a) * sin(b) * cos(c)) + (sin(a) * sin(c))) \
				* fdf->p_p[row][col].z);
	tmp.y = (sin(a) * cos(b) * fdf->p_p[row][col].x);
	tmp.y += (((sin(a) * sin(b) * sin(c)) + (cos(a) * cos(c))) \
				* fdf->p_p[row][col].y);
	tmp.y += (((sin(a) * sin(b) * cos(c)) - (cos(a) * sin(c))) \
				* fdf->p_p[row][col].z);
	fdf->p_p[row][col].x = tmp.x;
	fdf->p_p[row][col].y = tmp.y;
	center(fdf, row, col);
}

/* scales given point by multiplying it with fdf->scale.
 Stores it in p_p struct so that points stay the same
 and can be reused with the keyhooks */
static void	scale(t_points *p, t_fdf_vars *fdf, int row, int col)
{
	fdf->p_p[row][col].x = p->x * fdf->scale - (fdf->width / 2 * fdf->scale);
	fdf->p_p[row][col].y = p->y * fdf->scale - (fdf->height / 2 * fdf->scale);
	fdf->p_p[row][col].z = fdf->points[row][col].z * fdf->z_scale;
	fdf->p_p[row][col].color = fdf->points[row][col].color;
}
