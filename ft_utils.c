/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:51:47 by abarbosa          #+#    #+#             */
/*   Updated: 2022/09/06 14:53:13 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	if ((x >= 0 && y >= 0 && x < (*ft_statics(X)) && y < (*ft_statics(Y))) && data->addr)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}


int     ft_atoi(const char *str)
{
        unsigned int    result;
        int                             sign;

        sign = 1;
        result = 0;
        while ((*str > 8 && *str < 14) || *str == 32)
                str++;
        if (*str == 43 || *str == 45)
        {
                if (*str == 45)
                        sign = -1;
                str++;
        }
        while (*str > 47 && *str < 58)
        {
                result = 10 * result + *str - 48;
                str++;
                if (result > INT_MAX)
                        break ;
        }
        if ((result == (unsigned int)INT_MAX + 1 && sign == -1)
                || result <= INT_MAX)
                return (sign * result);
        return (0);
}
