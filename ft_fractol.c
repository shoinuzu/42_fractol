#include "ft_fractol.h"

int ft_move(int keycode, t_data *data)
{
    (void)keycode;
    if (keycode == 65362)
        (*ft_statics(SY)) -= 10;
    if (keycode == 65364)
        (*ft_statics(SY)) += 10;
    if (keycode == 65363)
        (*ft_statics(SX)) += 10;
    if (keycode == 65361)
        (*ft_statics(SX)) -= 10;
    mlx_clear_window(data->mlx, data->win);
    ft_mandelbrot(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int ft_zoom(int keycode, t_data *data)
{
    if (keycode == 119)
        (*ft_staticsf(Z)) *= 1.1;
    if (keycode == 115)
        (*ft_staticsf(Z)) *= 0.9;
    mlx_clear_window(data->mlx, data->win);
    ft_mandelbrot(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int ft_julia_complex(int keycode, t_data *data)
{
    if (keycode == 100)
        (*ft_statics_complex(J)).re -= 0.01;
    if (keycode == 101)
        (*ft_statics_complex(J)).re += 0.01;
    if (keycode == 102)
        (*ft_statics_complex(J)).im -= 0.01;
    if (keycode == 114)
        (*ft_statics_complex(J)).im += 0.01;
    mlx_clear_window(data->mlx, data->win);
    ft_mandelbrot(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int ft_key(int keycode, t_data *data)
{
    if ((65360 < keycode) && (keycode < 65365))
        return (ft_move(keycode, data));
    if ((keycode == 119) || (keycode == 115))
        return (ft_zoom(keycode, data));
    if (((keycode > 99) && (keycode < 103)) || (keycode == 114))
        return(ft_julia_complex(keycode, data));
    if (keycode == 65307)
    {
	    mlx_destroy_window(data->mlx, data->win);
	    return (0);
    }
    return (0);
}

void    ft_define_statics_mandelbrot(int y, int x)
{
    (*ft_statics(X)) = x;
    (*ft_statics(Y)) = y;
    (*ft_statics(SX)) = 0.;
    (*ft_statics(SY)) = 0;
    (*ft_staticsf(Z)) = 1;
    (*ft_statics(S)) = -42;
}

void    ft_define_statics_julia(int y, int x,char **argv)
{
    (*ft_statics(X)) = x;
    (*ft_statics(Y)) = y;
    (*ft_statics(SX)) = 0;
    (*ft_statics(SY)) = 0;
    (*ft_staticsf(Z)) = 1;
    (*ft_statics(S)) = 42;
    (*ft_statics_complex(J)).re = ft_atoi(argv[3]) / 1000;
    (*ft_statics_complex(J)).re = ft_atoi(argv[3]) / 1000;
}

int main(int argc, char **argv)
{
    static t_data	img;
    int x;

    if (argc < 2)
        return (0);
    x = ft_atoi(argv[2]);
    if (!ft_memcmp("julia", argv[1], 5))
        ft_define_statics_julia(x, x * 3 / 2, argv);
    else 
        ft_define_statics_mandelbrot(x, x * 3 / 2);
    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, (*ft_statics(X)), (*ft_statics(Y)), "Fract-ol!");
    img.img = mlx_new_image(img.mlx, (*ft_statics(X)), (*ft_statics(Y)));
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    ft_mandelbrot(&img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, (*ft_statics(SX)), (*ft_statics(SY)));
    mlx_key_hook(img.win, ft_key, &img);
    mlx_loop(img.mlx);
}

// int main()
// {
//     t_complex c;

//     c = ft_pc(1620.0 , 1080.0);
//     printf("%f\n%fw", c.re, c.im);
// }