/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:13:45 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:14:02 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitlen(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++len;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	str = malloc(sizeof(char *) * (ft_splitlen(s, c) + 1));
	if (!str)
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
