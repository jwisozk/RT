/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iplastun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:04:13 by jwisozk           #+#    #+#             */
/*   Updated: 2019/11/25 23:39:24 by iplastun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
//# include <SDL2/SDL.h>
# include "../lib/SDL2/SDL2.framework/Headers/SDL.h"



# define SCREEN_WIDTH	    601
# define SCREEN_HEIGHT      601
# define SCREEN_SIZE        (SCREEN_WIDTH * SCREEN_HEIGHT)
# define TITLE_WINDOW       "R4Y7r4c1N9_C4P031R4_CR3W"
# define DW				601
# define DH				601
# define EXTENSION		".cfg"
# define VW				1
# define VH				1
# define D				2
# define INF			1000
# define BACKGROUND		128, 128, 128
# define E				1e-6
# define SPHERE_OBJ		{SPHERE, &ft_sphere_intersect, &ft_sphere_fill}
# define PLANE_OBJ		{PLANE, &ft_plane_intersect, &ft_plane_fill}
# define CYLINDER_OBJ	{CYLINDER,  &ft_cylinder_intersect, &ft_cylinder_fill}
# define CONE_OBJ		{CONE,  &ft_cone_intersect, &ft_cone_fill}
# define ARR_OBJ		{SPHERE_OBJ, CYLINDER_OBJ, PLANE_OBJ, CONE_OBJ}
# define TANH(x)		tanh(x * M_PI / 180)
# define COS(x)			cos(x * M_PI / 180)
# define SIN(x)			sin(x * M_PI / 180)
# define CAM_T			{"camera", &ft_update_camera}
# define LIGHT_T		{"light", &ft_update_light}
# define SPHERE_T		{"sphere", &ft_update_sphere}
# define PLANE_T		{"plane", &ft_update_plane}
# define CYLINDER_T		{"cylinder", &ft_update_cylinder}
# define CONE_T			{"cone", &ft_update_cone}
# define ARR_TYPES		{CAM_T, LIGHT_T, SPHERE_T, PLANE_T, CYLINDER_T, CONE_T}
# define AMBIENT		"ambient"
# define POINT			"point"
# define DIRECTIONAL	"directional"
# define LIGHT_TYPES	{AMBIENT, POINT, DIRECTIONAL}
# define TYPE			"type"
# define INTENSITY		"intensity"
# define LOOK_AT		"look_at"
# define POSITION		"position"
# define CENTER			"center"
# define NORMAL			"normal"
# define COLOR			"color"
# define ANGLE			"angle"
# define RADIUS			"radius"
# define SPECULAR		"specular"
# define ROTATION		"rotation"
# define TRANSLATION	"translation"
# define TEAM			"R4Y7r4c1N9_C4P031R4"
# define PHOTO			".foto4ka"
# define PHOTO_W		1000
# define PHOTO_H		667
# define USAGE			"Usage: ./RTv1 <filename>"
# define ERROR  		"Error: "
# define ERROR_1		"Extension of file is incorrect."
# define ERROR_2		"Type # is invalid."
# define ERROR_3		"Curly braces in the file are not valid."
# define ERROR_4		"The length of the 4th rotation parameter should be 3."
# define ERROR_5		"The 4th parameter of rotation is invalid."
# define ERROR_6		"File not found."
# define ERROR_7		"File doesn' contain a camera."
# define ERROR_8		"File doesn't contain parameter of camera: look_at\""
# define ERROR_9		"File doesn't contain parameter of camera: position\""
# define ERROR_10_1		"Parameters of camera: \"position\" and \"look_at\""
# define ERROR_10_2		" are equal. Impossible to determine camera direction."
# define ERROR_10		ERROR_10_1 ERROR_10_2
# define ERROR_11		"Param \"type\" of light is invalid."
# define ERROR_12		"Param \"position\" of light is invalid."
# define ERROR_13		"Param \"intensity\" of light is invalid."
# define ERROR_14		"Param \"center\" of sphere is invalid."
# define ERROR_15		"Param \"radius\" of sphere is invalid."
# define ERROR_16		"Param \"color\" of sphere is invalid."
# define ERROR_17		"Param \"center\" of cylinder is invalid."
# define ERROR_18		"Param \"normal\" of cylinder is invalid."
# define ERROR_19		"Param \"radius\" of cylinder is invalid."
# define ERROR_20		"Param \"color\" of cylinder is invalid."
# define ERROR_21		"Param \"center\" of cone is invalid."
# define ERROR_22		"Param \"normal\" of cone is invalid."
# define ERROR_23		"Param \"angle\" of cone is invalid."
# define ERROR_24		"Param \"color\" of cone is invalid."
# define ERROR_25		"Param \"point\" of plane is invalid."
# define ERROR_26		"Param \"normal\" of plane is invalid."
# define ERROR_27		"Param \"color\" of plane is invalid."
# define ERROR_28		"Function close() failed."
# define ERROR_29		"Memory was not allocated."
# define ERROR_30		"Function mlx_init() return NULL."
# define ERROR_31		"Function mlx_new_window() return NULL."
# define ERROR_32		"Function mlx_new_image() return NULL."
# define ERROR_33		"Function get_next_line() return -1."
# define ERROR_34		"Function ft_new_lst() return NULL."
# define ERROR_35		"Function mlx_xpm_file_to_image() return NULL."

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_ang3
{
	int					x;
	int					y;
	int					z;
}						t_ang3;

typedef struct			s_ray
{
	t_vec3				*origin;
	t_vec3				*direct;
	double				t_min;
	double				t_max;
}						t_ray;

typedef enum			e_type_obj
{
	SPHERE = 0,
	CYLINDER,
	PLANE,
	CONE
}						t_type_obj;

typedef struct			s_arr_obj
{
	t_type_obj			type;
	void				(*ft_obj_intersect)();
	void				(*ft_obj_fill)();
}						t_arr_obj;

typedef struct			s_arr_type
{
	char				*type;
	void				(*ft_create_type)();
}						t_arr_type;

typedef struct			s_lst
{
	char				*type;
	void				*data;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_obj
{
	t_type_obj			type;
	void				*obj;
	void				*objects;
	double				t;
	struct s_obj		*next;

}						t_obj;

typedef struct			s_sphere
{
	t_vec3				*center;
	double				radius;
	int					color;
	int					specular;
	t_vec3				*translation;
	struct s_sphere		*next;
}						t_sphere;

typedef struct			s_cylinder
{
	t_vec3				*center;
	t_vec3				*normal;
	double				radius;
	int					color;
	int					specular;
	t_vec3				*translation;
	t_ang3				*rotation;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct			s_cone
{
	t_vec3				*center;
	t_vec3				*normal;
	double				angle;
	int					color;
	int					specular;
	t_vec3				*translation;
	t_ang3				*rotation;
	struct s_cone		*next;
}						t_cone;

typedef struct			s_plane
{
	t_vec3				*normal;
	t_vec3				*point;
	int					color;
	int					specular;
	t_vec3				*translation;
	t_ang3				*rotation;
	struct s_plane		*next;
}						t_plane;

typedef struct			s_light
{
	char				*type;
	double				intensity;
	t_vec3				*position;
	struct s_light		*next;
}						t_light;

typedef struct			s_cam
{
	t_vec3				*forward;
	t_vec3				*left;
	t_vec3				*up;
	t_vec3				*pos;
	t_vec3				*look_at;
}						t_cam;

typedef struct              s_sdl
{
	SDL_Window              *win;
	SDL_Renderer            *ren;
	SDL_Texture	            *tex;
	SDL_Event               e;
	int                     *pixels;
	int                     pitch;
}                           t_sdl;

typedef struct			s_point
{
	t_vec3				*point;
	t_vec3				*normal;
	int					color;
	int					specular;
	t_type_obj			type;
	t_vec3				*po;
	t_vec3				*center;
	t_vec3				*cam;
}						t_point;

typedef struct			s_data
{
	t_sdl				sdl;
	t_cam				*cam;
	t_light				*l;
	t_obj				*o;
	t_ray				*ray;
	t_point				*p;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
	t_cone				*cone;
	void				*pass;
}						t_data;

int						ft_key_press(int key, t_data *data);
int						ft_close_window(t_data *data);
char					*ft_msg(char *str);
t_vec3					*ft_create_vec3(double x, double y, double z);
t_ang3					*ft_create_ang3(int x, int y, int z);
t_ray					*ft_create_ray(t_vec3 *cam, t_vec3 *dir, double t_min,
						double t_max);
t_point					*ft_create_point(void);
t_vec3					*ft_cross_product(t_vec3 *a, t_vec3 *b);
t_vec3					*ft_multiply(double k, t_vec3 *v);
t_vec3					*ft_subtract(t_vec3 *v1, t_vec3 *v2);
t_vec3					*ft_add(t_vec3 *v1, t_vec3 *v2);
t_vec3					*ft_normalize_vec3(t_vec3 *v);
double					ft_lenv(t_vec3 *v);
double					ft_dot(t_vec3 *v1, t_vec3 *v2);
double					ft_max(double x, double y);
double					ft_min(double x, double y);
int						ft_rgb(int r, int g, int b);
int						ft_multiply_color(double k, int color, int specular);
t_obj					*ft_create_object(void *obj, t_type_obj type);
t_cam					*ft_create_camera(void);
t_light					*ft_create_light(t_data *data);
t_sphere				*ft_create_sphere(t_data *data);
t_cylinder				*ft_create_cylinder(t_data *data);
t_cone					*ft_create_cone(t_data *data);
t_plane					*ft_create_plane(t_data *data);
void					ft_update_camera(t_data *data, t_lst *lst);
void					ft_update_light(t_data *data, t_lst *lst);
void					ft_update_sphere(t_data *data, t_lst *lst);
void					ft_update_plane(t_data *data, t_lst *lst);
void					ft_update_cylinder(t_data *data, t_lst *lst);
void					ft_update_cone(t_data *data, t_lst *lst);
void					ft_cylinder_min(t_cylinder **c, t_lst *lst);
void					ft_cone_min(t_cone **c, t_lst *lst);
void					ft_plane_min(t_plane **p, t_lst *lst);
double					ft_calculate_sphere(t_ray *ray, t_sphere *s);
double					ft_calculate_cylinder(t_ray *ray, t_cylinder *c);
double					ft_calculate_cone(t_ray *ray, t_cone *c);
void					ft_check_valid(t_data *data);
t_vec3					*ft_translate(t_vec3 *o, t_vec3 *t);
t_vec3					*ft_rotate(t_vec3 *v, t_ang3 *a);
void					ft_get_scene(int fd, t_data *data);
void					ft_create_scene_objects(t_data *data);
int						*ft_rotation_order(int *arr, int array[3], char *str);
double					*ft_new_arr_d(char *a, char *b, char *c);
int						*ft_new_arr_i(char *a, char *b, char *c, char *str);
void					ft_check_camera(t_data *data);
void					ft_check_light(t_data *data);
void					ft_check_sphere(t_data *data);
void					ft_check_cylinder(t_data *data);
void					ft_check_cone(t_data *data);
void					ft_check_plane(t_data *data);
void					ft_draw(t_data *data);
void					ft_camera_look_at(t_data *data);
void					ft_camera_ray(t_data *data, int x, int y);
double					ft_lighting(t_point *p, t_light *l, t_obj *o);
t_obj					*ft_scene_intersect(t_obj *o, t_ray *ray);
void					ft_sphere_intersect(t_ray *ray, t_obj *o);
void					ft_plane_intersect(t_ray *ray, t_obj *o);
void					ft_cylinder_intersect(t_ray *ray, t_obj *o);
void					ft_cone_intersect(t_ray *ray, t_obj *o);
void					ft_sphere_fill(t_obj *obj, t_point *p, t_ray *ray);
void					ft_cylinder_fill(t_obj *obj, t_point *p, t_ray *ray);
void					ft_plane_fill(t_obj *obj, t_point *p, t_ray *ray);
void					ft_cone_fill(t_obj *obj, t_point *p, t_ray *ray);
t_lst					*ft_new_lst(char *type, void *data);
void					ft_add_lst(t_lst **head, t_lst *new);
void					ft_check_argv(char *str);
void					ft_open_file(char *name, int *fd);
void					ft_close_file(const int fd);
int						ft_compare_vec3(t_vec3 *a, t_vec3 *b);
int						ft_check_substr(char *str, int num);
void    				ft_sdl2_main(t_sdl   *sdl);
void    				ft_sdl2_key_quit(SDL_Event e, int *running);
#endif
