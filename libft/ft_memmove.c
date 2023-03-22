/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:53:24 by nbechard          #+#    #+#             */
/*   Updated: 2022/02/28 12:24:06 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)dst;
	d = (unsigned char *)src;
	if (s > d)
	{
		while (i < len)
		{
			s[len - 1] = d[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			s[i] = d[i];
			i++;
		}
	}
	return (dst);
}
