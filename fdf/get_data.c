/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:53:28 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 10:40:31 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_height_and_width(t_fdf_vars *fdf);
static void	put_data_in_arr(t_fdf_vars *fdf, int fd);
static void	free_put_data(char *tmp, t_fdf_vars *fdf);

int	read_data(t_fdf_vars *fdf)
{
	int	fd;

	fd = open(fdf->map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Could not open file\n");
		return (1);
	}
	put_data_in_arr(fdf, fd);
	get_height_and_width(fdf);
	close(fd);
	return (0);
}

/* reads file line by line. Creates 2d fdf->data_arr with a str for each row*/
static void	put_data_in_arr(t_fdf_vars *fdf, int fd)
{
	int		more_to_read;
	char	*tmp;
	char	*buf;

	more_to_read = YES;
	while (more_to_read == YES)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			more_to_read = NO;
		else
		{
			buf = ft_strjoin(fdf->data_str, tmp);
			free_put_data(tmp, fdf);
			fdf->data_str = buf;
		}
	}
	fdf->data_arr = ft_split(fdf->data_str, '\n');
	free(fdf->data_str);
	fdf->data_str = NULL;
	return ;
}

/* frees data_str and tmp to be ready for the next interation 
in put_data_in_arr */
static void	free_put_data(char *tmp, t_fdf_vars *fdf)
{
	if (fdf->data_str[0] != '\0')
	{
		free(fdf->data_str);
		fdf->data_str = NULL;
	}
	free(tmp);
	tmp = NULL;
	return ;
}

/* using ft_str_count to get map's width, iteration through data_arr[i]
to get map's height */
static void	get_height_and_width(t_fdf_vars *fdf)
{
	int	i;

	fdf->width = ft_str_count(fdf->data_arr[0], ' ');
	i = 0;
	while (fdf->data_arr[i])
	{
		fdf->height++;
		i++;
	}
	return ;
}
