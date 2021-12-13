/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:18 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/23 16:53:15 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf_vars	fdf;

	if (argc != 2)
	{
		ft_printf("Number of arguments has to be 1\n");
		return (1);
	}
	init_fdf_vars(&fdf);
	fdf.map_path = argv[1];
	if (read_data(&fdf) != 0)
		exit (0);
	if (put_data_in_points(&fdf) != 0)
		exit (0);
	draw_map(&fdf);
	return (0);
}

void	init_fdf_vars(t_fdf_vars *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->addr = NULL;
	fdf->bits_per_pixel = 0;
	fdf->endian = 0;
	fdf->data_str = "\0";
	fdf->width = 0;
	fdf->height = 0;
	fdf->points = NULL;
	fdf->p_p = NULL;
	fdf->rot_x = asin(tan(M_PI / 6));
	fdf->rot_y = M_PI / 4;
	fdf->rot_z = M_PI / 4;
	fdf->scale = 1;
	fdf->z_scale = 1;
	fdf->x_center = 0;
	fdf->y_center = 0;
	fdf->i = 0;
	fdf->j = 0;
	return ;
}

int	close_win(t_fdf_vars *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	free_points(fdf, fdf->height);
	exit(0);
	return (0);
}

void	free_points(t_fdf_vars *fdf, int height)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		free(fdf->p_p[i]);
		fdf->p_p[i] = NULL;
		free(fdf->points[i]);
		fdf->points[i] = NULL;
		i++;
	}
	free(fdf->points);
	fdf->points = NULL;
	free(fdf->p_p);
	fdf->p_p = NULL;
}
