/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbechtol <fbechtol@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:22:11 by fbechtol          #+#    #+#             */
/*   Updated: 2021/11/15 13:38:14 by fbechtol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ----------------------------- Includes ---------------------------------- */

# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* ----------------------------- Defines ---------------------------------- */

# define WIDTH 2560
# define HEIGHT 1600
# define FRAME 50

/* ----------------------------- Key Codes ---------------------------------- */

# define ESC_K 53
# define LEFT_K 123
# define RIGHT_K 124
# define DOWN_K 125
# define UP_K 126
# define PLUS_K 24
# define MINUS_K 27
# define O_K 31
# define P_K 35
# define X_K 7
# define S_K 1
# define Y_K 16
# define T_K 17
# define Z_K 6
# define A_K 0

/* ----------------------------- Structures -------------------------------- */

typedef struct s_points
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_points;

typedef struct s_fdf_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*map_path;
	char		*data_str;
	char		**data_arr;
	int			width;
	int			height;
	t_points	**points;
	t_points	**p_p;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			scale;
	int			z_scale;
	int			x_center;
	int			y_center;
	int			i;
	int			j;
}				t_fdf_vars;

typedef struct s_bresenham_vars
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;
}				t_bresenham_vars;

/*  ------------------------ Function prototypes --------------------------- */

/*  ------------------------ fdf_main.c--------------------------- */

/* initializes the values in the fdf struct */
void	init_fdf_vars(t_fdf_vars *fdf);

/* uses destroies window and exits.
 Needed for mlx_hook */
int		close_win(t_fdf_vars *fdf);

/* frees all points */
void	free_points(t_fdf_vars *fdf, int height);

/*  ------------------------ get_data.c--------------------------- */

/* main read fct: opens map_file and calls subfcts to read it */
int		read_data(t_fdf_vars *fdf);

/*  ------------------------ put_data.c--------------------------- */

/* iterates through data_arr and uses subfcts to store the coordinates 
in t_points struct */
int		put_data_in_points(t_fdf_vars *fdf);

/*  ------------------------ draw.c--------------------------- */

/* main draw fct: doing mlx stuff and calling subfcts doing the drawing */
void	draw_map(t_fdf_vars *fdf);

/* creates the image, the map in the image through a subfct
 and puts it in the window. Gets called by the keyhooks */
void	map_to_image(t_fdf_vars *fdf_data);

/*  ------------------------ draw_utils.c--------------------------- */

/* slight variation from mlx_pixel_put */
void	pixel_put(t_fdf_vars *fdf, int x, int y, int color);

/* defines fdf->scale by checking the ratio of map- and windowsize */
void	get_scale(t_fdf_vars *fdf);

/* checks if a point is inside the given frame */
int		check_in_frame(t_points p);

/* centers a point approx. by adding window width/2 and height/3 */
void	center(t_fdf_vars *fdf, int row, int col);

/*  ------------------------ bresenham.c--------------------------- */

/* using the bresenham algorithm to draw line between two given points */
void	bham(t_points p0, t_points p1, t_fdf_vars *fdf);

/*  ------------------------ bresenham.c--------------------------- */

/* checks with subfcts which key got pressed.
 Calls map_to_image again*/
int		deal_key(int key, t_fdf_vars *fdf);

#endif
