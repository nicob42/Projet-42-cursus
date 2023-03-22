/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:03:17 by alrusso           #+#    #+#             */
/*   Updated: 2022/04/29 10:13:42 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		index;

	index = 0;
	while (s1[index])
		index++;
	str = malloc((index + 1) * sizeof(char));
	if (str == 0)
		return (0);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
