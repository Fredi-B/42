/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:27 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 13:49:15 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rot(int key, t_fdf_vars *fdf);
static void	key_scale(int key, t_fdf_vars *fdf);
static void	key_shift(int key, t_fdf_vars *fdf);

int	deal_key(int key, t_fdf_vars *fdf)
{
	key_rot(key, fdf);
	key_scale(key, fdf);
	key_shift(key, fdf);
	if (key == ESC_K)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_points(fdf, fdf->height);
		exit (0);
	}
	map_to_image(fdf);
	return (0);
}

/* rotates map if defined keys got pressed */
static void	key_rot(int key, t_fdf_vars *fdf)
{
	if (key == X_K)
		fdf->rot_x += M_PI / 24;
	if (key == S_K)
		fdf->rot_x -= M_PI / 24;
	if (key == Y_K)
		fdf->rot_y += M_PI / 24;
	if (key == T_K)
		fdf->rot_y -= M_PI / 24;
	if (key == Z_K)
		fdf->rot_z += M_PI / 24;
	if (key == A_K)
		fdf->rot_z -= M_PI / 24;
}

/* zooms in and out if defined keys got pressed */
static void	key_scale(int key, t_fdf_vars *fdf)
{
	if (key == PLUS_K)
	{
		if (fdf->scale > 35)
			fdf->scale += 2;
		else if (fdf->scale < 2)
			fdf->scale += 1;
		else if (fdf->scale >= 2 && fdf->scale <= 35)
			fdf->scale += 1;
	}
	if (key == MINUS_K)
	{
		if (fdf->scale > 35)
			fdf->scale -= 3;
		else if (fdf->scale < 5 && fdf->scale > 1)
			fdf->scale -= 1;
		else if (fdf->scale >= 2 && fdf->scale <= 35)
			fdf->scale -= 2;
	}
	if (key == O_K)
		fdf->z_scale += 1;
	if (key == P_K)
		fdf->z_scale -= 1;
}

/* shifts map if defined keys got pressed */
static void	key_shift(int key, t_fdf_vars *fdf)
{
	if (key == LEFT_K)
		fdf->x_center -= 20;
	if (key == RIGHT_K)
		fdf->x_center += 20;
	if (key == UP_K)
		fdf->y_center -= 20;
	if (key == DOWN_K)
		fdf->y_center += 20;
}
