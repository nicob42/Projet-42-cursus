/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:09:46 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 09:09:46 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t	i;
	char	*sd;
	char	*sr;

	sd = dst;
	sr = (void *)src;
	i = 0;
	if (sr < sd)
	{
		i++;
		while (i <= size)
		{
			sd[size - i] = sr[size - i];
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			sd[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
