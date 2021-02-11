/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:45:29 by mscot             #+#    #+#             */
/*   Updated: 2021/02/08 21:45:51 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "libft.h"

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define TO_RED 16
# define TO_GREEN 8
# define TO_BLUE 0

/*
** lambert_shading
** K_D - diffusion coefficient
*/

# define K_D 30

/*
** specular_shading
** K_D - diffusion coefficient
*/

# define K_S 30
# define P 60

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct	s_resolution
{
	long	width;
	long	height;
}				t_resolution;

typedef struct	s_ambient
{
	double		ratio;
	t_vector	color;
}				t_ambient;

typedef struct	s_camera
{
	t_ray	ray;
	long	fov;
}				t_camera;

typedef struct	s_light
{
	t_vector	origin;
	double		brightness;
	t_vector	color;
}				t_light;

typedef struct	s_object
{
	char			type[3];

	t_vector		origin;
	t_vector		direction;
	t_vector		point_2;
	t_vector		point_3;
	t_vector		color;

	double			radius;
	double			diameter;
	double			height;
	double			side;

}				t_object;

typedef struct	s_image
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	**canvas;
	unsigned int	image_size;
}				t_image;

typedef struct	s_scene
{
	t_list			*camera_list;
	t_list			*object_list;
	t_list			*light_list;
	t_resolution	*resolution;
	t_ambient		*ambient;
	t_image			*image;
	int				save;
}				t_scene;

typedef struct	s_nearest
{
	double		dist_min;
	t_object	*obj_hit;
}				t_nearest;

typedef struct	s_roots
{
	double	t1;
	double	t2;
}				t_roots;

/*
** mlx
*/

typedef	struct	s_image_mlx
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image_mlx;

typedef struct	s_data
{
	t_scene		*scene;
	void		*id;
	void		*window;
	t_image_mlx	image;
	t_list		*current_camera;
}				t_data;

typedef struct	s_cylinder_calc
{
	t_vector	ca;
	t_vector	oc;
	double		caca;
	double		card;
	double		caoc;
	double		a;
	double		b;
	double		c;
	double		h;
}				t_cylinder_calc;

typedef struct	s_triangle_calc
{
	t_vector	vec_1_to_0;
	t_vector	vec_2_to_0;
	t_vector	rov_0;
	t_vector	n;
	t_vector	q;
	double		d;
	double		u;
	double		v;
	double		t;
}				t_triangle_calc;

/*
** look at matrix
*/

typedef struct	s_lk_at_mtx
{
	double	**lam;
}				t_lk_at_mtx;

/*
** main.c
*/

int				get_next_line(int fd, char **line);

/*
** atof
*/
double			ft_atof(const char *str);
int				ft_skip_float(const char *line);
int				ft_skip_vector(const char *line);
t_vector		ft_atovector(const char *line);
int				atoresolution(const char *str, int max_num);

/*
** validation functions
*/

int				is_direction_valid(t_vector direction);
int				is_color_valid(t_vector color);
int				is_scene_valid(t_scene *scene);
int				is_beginning_of_num(const char *line);

/*
** validation scene processor
*/

int				is_line_valid(const char *line);

/*
** validation scene utils
*/

int				is_vector_valid(char *line_p);
int				is_resolution_valid(char *resolution);
int				is_ambient_valid(char *ambient);
int				is_camera_valid(char *camera);
int				is_light_valid(char *light);

/*
** validation scene objects
*/

int				is_plain_valid(char *plain);
int				is_sphere_valid(char *sphere);
int				is_square_valid(char *square);
int				is_cylinder_valid(char *cylinder);
int				is_triangle_valid(char *triangle);

/*
** get_scene_from_file
*/

t_scene			*get_scene_from_file(char *file, int save);
int				get_object(t_scene **s, const char *l);
void			get_object_type(t_object **object, const char *line);

/*
** get_scene_from_file_objects
*/

t_object		*get_triangle(const char *line);
t_object		*get_cylinder(const char *line);
t_object		*get_square(const char *line);
t_object		*get_sphere(const char *line);
t_object		*get_plain(const char *line);

/*
** get_scene_from_file_utils
*/

t_light			*get_light(const char *line);
t_camera		*get_camera(const char *line);
t_ambient		*get_ambient(const char *line, t_ambient *validation);
t_resolution	*get_resolution(const char *line,
								t_resolution *validation, int save);

/*
** get_scene_objects_creation_destruction
*/

void			free_scene(t_scene **scene);
t_scene			*new_scene(void);
void			free_lam(t_lk_at_mtx	*lam);

/*
**  vector calculation basic
*/

t_vector		vector_sum(t_vector vector_1, t_vector vector_2);
t_vector		vector_sub(t_vector vector_1, t_vector vector_2);
t_vector		vector_dev(t_vector vector, double num);
t_vector		vector_mul_by_scal(t_vector vector, double num);

/*
**  vector calculation binary
*/

t_vector		vector_cross(t_vector a, t_vector b);
double			vector_dot(t_vector vector_1, t_vector vector_2);
double			vector_length(t_vector vector);
t_vector		vector_normalization(t_vector vector);

/*
**  vector calculation color
*/

t_vector		vector_sum_color(t_vector vector_1, t_vector vector_2);
unsigned int	hex_color_to_dec(unsigned int hex_color, unsigned int color);
unsigned int	vector_to_color(t_vector color);

/*
** look at matrix
*/

t_lk_at_mtx		*new_look_at_matrix(t_camera *camera);
t_vector		world_to_cam_vec(t_lk_at_mtx *lam, t_vector obj);
t_vector		world_to_cam_dir(t_lk_at_mtx *lam, t_vector obj);
t_ray			ray_to_cam(t_lk_at_mtx *lam, t_ray ray);

/*
** image.c
*/

void			image_free_canvas(unsigned int **canvas);
unsigned int	**image_pixels(unsigned int height, unsigned int width);
t_image			*image_new(long width, long height);

/*
** render_engine.c
*/

t_vector		ray_trace(t_ray ray, t_scene *scene);
t_image			*render(t_scene *scene, t_camera *camera);
void			render_processor(t_scene *scene, int save);

/*
** render_engine_objects_creation.c
*/

t_vector		new_vector(double x, double y, double z, int norm);
t_ray			new_ray(double x, double y, t_camera *camera, t_scene *scene);
t_roots			fill_roots(double t1, double t2);

/*
** render_engine_objects_intersection
*/

t_vector		object_normal(t_vector hit_point, t_object *object, t_ray ray);
t_roots			object_intersection(t_ray ray, t_object *object);
t_nearest		find_nearest_rt(t_ray ray, t_scene *scene);
t_roots			quadratic_equation(double a, double b, double c);

/*
** render_engine_lighting
*/

t_vector		light_calculation(t_vector hit_pos, t_vector hit_normal,
							t_light *light, t_ray ray);
double			specular_shading(t_vector hit_pos, t_vector hit_normal,
							t_light *light, t_ray ray);
double			lambert_shading(t_vector hit_pos, t_vector hit_normal,
							t_light *light);
int				is_light_ray_blocked(t_vector hit_pos, t_scene *scene,
							t_list *lights);

/*
** image_to_file
*/

int				to_file_processor(t_scene *scene);
int				to_file_bmp(t_image image, char *file_name);
void			to_file_bmp_add_header(int fd, int width, int height);

/*
** sphere
*/

t_roots			sphere_intersection(t_ray ray, t_object *sphere);
t_vector		sphere_normal(t_object *sphere, t_vector surface_point,
						t_ray ray);

/*
** triangle
*/

t_roots			triangle_intersection(t_ray ray, t_object *triangle);
t_vector		triangle_normal(t_object *triangle, t_vector surface_point,
						t_ray ray);

/*
** plane
*/

t_roots			plane_intersection(t_ray ray, t_object *plane);
t_vector		plane_normal(t_object *plane, t_vector surface_point,
						t_ray ray);

/*
** cylinder
*/

t_roots			cylinder_intersection(t_ray ray, t_object *cylinder);
t_vector		cylinder_normal(t_object *cylinder, t_vector surface_point,
						t_ray ray);

/*
** square
*/

t_roots			square_intersection(t_ray ray, t_object *plane);
t_vector		square_normal(t_object *plane, t_vector surface_point,
						t_ray ray);

/*
** mlx_processor
*/

void			my_mlx_pixel_put(t_image_mlx *data, int x, int y, int color);
int				w_close(t_data *info);
void			pixels_to_canvas(t_data *data, t_image *image);
int				key_hook_processor(int key_hook, t_data *data);
void			print_mlx(t_scene *scene);

/*
** mlx_check_screen
*/

void			check_screen_size(void *mlx_ptr, t_scene **scene);

#endif
