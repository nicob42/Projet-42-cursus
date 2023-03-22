/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:24:43 by alrusso           #+#    #+#             */
/*   Updated: 2022/04/29 10:13:55 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const	char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	if (dstsize == 0)
		return (slen);
	if (dstsize < dlen)
		return (slen + dstsize);
	else
	{
		while (src[j] && (dlen + j) < dstsize)
			dst[i++] = src[j++];
		if ((dlen + j) == dstsize && dlen < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (slen + dlen);
	}
}
