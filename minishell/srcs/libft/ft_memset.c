/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:10:04 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 09:10:04 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*dst;

	dst = pointer;
	while (count > 0)
	{
		*dst = value;
		dst ++;
		count --;
	}
	return (pointer);
}
