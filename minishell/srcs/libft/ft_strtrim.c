/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:09:38 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:09:45 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_occ(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_occ(s1[start], set))
		start++;
	while (end > start && ft_occ(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (0);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
