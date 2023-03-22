/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:55:38 by nbechard          #+#    #+#             */
/*   Updated: 2022/02/28 10:06:19 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	*c;

	i = 0;
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (i < n)
	{
		if (b[i] != c[i])
			return (b[i] - c[i]);
		i++;
	}
	return (0);
}
