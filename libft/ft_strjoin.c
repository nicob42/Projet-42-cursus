/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:03:23 by nbechard          #+#    #+#             */
/*   Updated: 2022/02/28 10:11:54 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stotal_len;
	char	*rtrn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	stotal_len = s1_len + s2_len + 1;
	rtrn = malloc(sizeof(char) * stotal_len);
	if (!rtrn)
		return (0);
	ft_memmove(rtrn, s1, s1_len);
	ft_memmove(rtrn + s1_len, s2, s2_len);
	rtrn[stotal_len - 1] = '\0';
	return (rtrn);
}
