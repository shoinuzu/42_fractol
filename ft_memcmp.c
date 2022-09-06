/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbosa <abarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:04:48 by abarbosa          #+#    #+#             */
/*   Updated: 2021/10/19 11:05:37 by abarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
        size_t  i;

        i = 0;
        while (i < n)
        {
                if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
                        return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
                i++;
        }
        return (0);
}