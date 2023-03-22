/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:09:58 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:10:06 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int x)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)x)
		{
			return ((char *)&(str)[i]);
		}
		i--;
	}
	return (0);
}
