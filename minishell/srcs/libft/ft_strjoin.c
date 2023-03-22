/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:11:58 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:12:05 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lengh1;
	size_t	lengh2;
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lengh1 = ft_strlen(s1);
	lengh2 = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (lengh1 + lengh2));
	while (s1[j] != '\0')
	{
		s3[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	return (s3);
}
