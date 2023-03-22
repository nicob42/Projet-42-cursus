/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:08:00 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 09:08:00 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned long int	i;
	char				*p;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
		{
			p = &((char *)str)[i];
			return (p);
		}
		i++;
	}
	return (0);
}
