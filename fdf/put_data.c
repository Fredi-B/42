/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:37:53 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 18:40:02 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_and_free(t_fdf_vars *fdf, char *line, int i, int j);
static int	malloc_points(t_fdf_vars *fdf);

int	put_data_in_points(t_fdf_vars *fdf)
{
	int		i;
	int		j;
	char	**line;

	if (malloc_points(fdf) != 0)
		return (1);
	i = 0;
	while (fdf->data_arr[i])
	{
		line = ft_split(fdf->data_arr[i], ' ');
		j = 0;
		while (line[j])
		{
			put_and_free(fdf, line[j], i, j);
			j++;
		}
		free(fdf->data_arr[i]);
		fdf->data_arr[i] = NULL;
		free(line);
		line = NULL;
		i++;
	}
	free(fdf->data_arr);
	fdf->data_arr = NULL;
	return (0);
}

/* 2d malloc for fdf->points and fdf->p_p */
static int	malloc_points(t_fdf_vars *fdf)
{
	fdf->points = (t_points **) malloc(sizeof(t_points *) * (fdf->height + 1));
	fdf->p_p = (t_points **) malloc(sizeof(t_points *) * (fdf->height + 1));
	if (fdf->points == NULL || fdf->p_p == NULL)
	{
		ft_printf("Error: malloc");
		free(fdf->points);
		free(fdf->p_p);
		return (1);
	}
	fdf->i = 0;
	while (fdf->i < fdf->height + 1)
	{
		fdf->points[fdf->i] = (t_points *) malloc(sizeof(t_points) \
			* (fdf->width + 1));
		fdf->p_p[fdf->i] = (t_points *) malloc(sizeof(t_points) \
			* (fdf->width + 1));
		if (fdf->points[fdf->i] == NULL || fdf->p_p[fdf->i] == NULL)
		{
			ft_printf("Error: malloc");
			free_points(fdf, fdf->i);
			return (1);
		}
		fdf->i++;
	}
	return (0);
}

/* stores x, y, z and color in fdf->points. frees the line */
static void	put_and_free(t_fdf_vars *fdf, char *line, int i, int j)
{
	char	**value_line;

	fdf->points[i][j].x = j;
	fdf->points[i][j].y = i;
	value_line = ft_split(line, ',');
	fdf->points[i][j].z = ft_atoi(value_line[0]);
	fdf->points[i][j].color = ft_atox(value_line[1]);
	if (fdf->points[i][j].color == 16777215)
	{
		if (fdf->points[i][j].z < 0)
			fdf->points[i][j].color -= (-1 * fdf->points[i][j].z * 6100);
		else
			fdf->points[i][j].color -= (fdf->points[i][j].z * 6100);
	}
	free(line);
	line = NULL;
	free(value_line[0]);
	value_line[0] = NULL;
	free(value_line[1]);
	value_line[1] = NULL;
	free(value_line);
	value_line = NULL;
	return ;
}
