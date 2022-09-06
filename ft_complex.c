/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:07:53 by abarbosa          #+#    #+#             */
/*   Updated: 2022/09/06 15:42:48 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_complex	ft_pc(float x, float y)
{
	t_complex to_return;
	x += *ft_statics(SX);
	y += *ft_statics(SY);
	
	if (*ft_statics(S) > 0)
	{
	to_return.re = (((x * 3 / (*ft_statics(X))) - 1.5) / (*ft_staticsf(Z)));
	to_return.im = ((2 - ((y * 2 / (*ft_statics(Y))) + 1)) / (*ft_staticsf(Z)));
	}
	else
	{
	to_return.re = (((x * 3 / (*ft_statics(X))) - 2) / (*ft_staticsf(Z)));
	to_return.im = ((2 - ((y * 2 / (*ft_statics(Y))) + 1)) / (*ft_staticsf(Z)));
	}
	return (to_return);
}

t_complex	ft_complex_addition(t_complex c1, t_complex c2)
{
	t_complex	to_return;

	to_return.re = c1.re + c2.re;
	to_return.im = c1.im + c2.im;
	return (to_return);
}

t_complex	ft_complex_multiplication(t_complex c1, t_complex c2)
{
	t_complex	to_return;

	to_return.re = (c1.re * c2.re) - (c1.im * c2.im);
	to_return.im = (c1.im * c2.re) + (c1.re * c2.im);
	return (to_return);	
}

double		ft_modulus_complex(t_complex c)
{
	double	to_return;

	to_return = (sqrt((c.re * c.re) + (c.im * c.im)));
	return (to_return);
}