/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:27:42 by abarbosa          #+#    #+#             */
/*   Updated: 2022/09/06 15:23:45 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_ms(t_complex c, int control, t_complex a)
{
	if (*ft_statics(S) < 0)
	{
		if (control && ((ft_modulus_complex(c) < 2)))
	    	return (ft_ms(ft_complex_addition(ft_complex_multiplication(c, c), a), control - 1, a));
		else
			return (pow(control, 3));
	}
	else if (*ft_statics(S) > 0)
	{
		if (control && ((ft_modulus_complex(a) < 2)))
	    	return (ft_ms(c, control - 1, ft_complex_addition(ft_complex_multiplication(a, a), (*ft_statics_complex(J)))));
		else
			return (pow(control, 3));
	}
	return (0);
}

void    ft_draw_normal(int x, int y, t_data *data)
{
    int i;
    int j;
    t_complex c;

    i = 0;
    j = 0;
    c.re = 0.0;
    c.im = 0.0;
    while (i < 6)
    {
        j = 0;
        while (j < 6)
        {
            ft_mlx_pixel_put(data, x + i, y + j, ft_ms(c, 255, ft_pc(x + i, y + j)));
            j++;
        }
        i++;
    }
}

void    ft_draw_color(int x, int y, int v, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 6)
    {
        j = 0;
        while (j < 6)
        {
            ft_mlx_pixel_put(data, x + i, y + j, v);
            j++;
        }
        i++;
    }
}


void    ft_draw_box(int x, int y, t_data *data)
{
	t_point f;
	
	f = ft_check_box(x, y, data);
	if ((f.x > -5) && (f.x < 5))
		ft_draw_color(x + 1, y + 1, f.y, data);
	else
		ft_draw_normal(x + 1, y + 1, data);
}


t_point     ft_check_horizontal(int x, int y, t_data *data)
{
    int i;
	int tmp;
    t_point to_return;
    t_complex c;

    i = 0;
	tmp = 0;
    to_return.x = 0;
    c.re = 0.0;
    c.im = 0.0;
    to_return.x = ft_ms(c, 255, ft_pc(x, y));
    to_return.y = to_return.x;
    ft_mlx_pixel_put(data, x, y, to_return.x);
    i = 1;
    while (i < 8)
    {
        tmp = ft_ms(c, 255, ft_pc(x, y + i));
		to_return.x -= tmp;
        ft_mlx_pixel_put(data, x, y + i, tmp);
        i++;
    }
    return (to_return);
}

t_point     ft_check_vertical(int x, int y, t_data *data)
{
    int i;
	int tmp;
    t_point to_return;
    t_complex c;

    i = 0;
	tmp = 0;
    to_return.x = 0;
    c.re = 0.0;
    c.im = 0.0;
    to_return.x = ft_ms(c, 255, ft_pc(x, y + i));
    to_return.y = to_return.x;
    ft_mlx_pixel_put(data, x, y, to_return.x);
    i = 1;
    while (i < 7)
    {
        tmp = ft_ms(c, 255, ft_pc(x + i, y));
		to_return.x -= tmp;
        ft_mlx_pixel_put(data, x + i, y, tmp);
        i++;
    }
    return (to_return);
}

t_point     ft_check_box(int x, int y, t_data *data)
{
    t_point to_return;

    to_return = ft_check_horizontal(x, y, data);
    to_return.x += ft_check_horizontal(x + 7, y, data).x;
    to_return.x += ft_check_vertical(x, y, data).x;
    to_return.x += ft_check_vertical(x, y + 7, data).x;
    return (to_return);
}
