/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:10:19 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:10:28 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;

	i = 0;
	litlen = ft_strlen(little);
	if (litlen == 0)
		return ((char *)big);
	if (len != 0)
	{
		while (big[i] != '\0' && i <= len - litlen)
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0')
				j++;
			if (j == litlen)
				return ((char *)&big[i]);
			i++;
		}
	}
	return (0);
}
