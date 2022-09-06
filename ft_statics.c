/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:40:49 by abarbosa          #+#    #+#             */
/*   Updated: 2022/09/06 14:39:30 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int   *ft_statics(t_statics t)
{
    static int      x;
    static int      y;
    static int      sx;
    static int      sy;
    static int      s;

    if (t == X)
        return (&x);
    if (t == Y)
        return (&y);
    if (t == SX)
        return (&sx);
    if (t == SY)
        return (&sy);
    if (t == S)
        return (&s);
    return (NULL);
}

t_complex   *ft_statics_complex(t_statics t)
{
    static t_complex j;

    if (t == J)
        return (&j);
    return (NULL);
}

float       *ft_staticsf(t_statics t)
{
    static float    z;

    if (t == Z)
        return (&z);
    return (NULL);
}