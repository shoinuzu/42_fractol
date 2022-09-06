#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef	struct	s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef	struct	s_point 
{
	int x;
	int y;
}		t_point;

typedef struct	s_complex
{
	float re;
	float im;
}		t_complex;

typedef	struct	s_vars 
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct	s_all
{
	t_data	*data;
	t_vars	*vars;
}		t_all;

typedef	enum s_statics
{
	X,
	Y,
	Z,
	J,
	SX,
	SY,
	S
}		t_statics;

int 		ft_memcmp(const void *s1, const void *s2, size_t n);
double		ft_modulus_complex(t_complex c);
t_complex	ft_complex_multiplication(t_complex c1, t_complex c2);
t_complex	ft_complex_addition(t_complex c1, t_complex c2);
t_complex	ft_pc(float x, float y);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_mandelbrot(t_data *data);
void    	ft_draw_box(int x, int y, t_data *data);
void    	ft_julia(t_data *data);
int    		*ft_statics(t_statics t);
float    	*ft_staticsf(t_statics t);
t_complex   *ft_statics_complex(t_statics t);
t_point     ft_check_box(int x, int y, t_data *data);
t_point     ft_check_horizontal(int x, int y, t_data *data);
t_point     ft_check_vertical(int x, int y, t_data *data);
int			ft_ms(t_complex c, int control, t_complex a);
int		    ft_atoi(const char *str);