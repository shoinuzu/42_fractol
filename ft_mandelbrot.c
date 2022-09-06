/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:59:53 by abarbosa          #+#    #+#             */
/*   Updated: 2022/09/06 15:43:52 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void    ft_mandelbrot(t_data *data)
{
    int         x;
    int         y;

    x = 0;
    while (x < (*ft_statics(X)))
    {
        y = 0;
        while ((y - 8) < ((*ft_statics(Y)) / 2))
        {
            ft_draw_box(x, y, data);
            ft_draw_box(x, (*ft_statics(Y) - (y - 8)), data);
            y += 8;
        }
        x += 8;
    }
}