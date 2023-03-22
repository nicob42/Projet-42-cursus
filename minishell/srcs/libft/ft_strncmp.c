/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:10:35 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:10:44 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t lenght)
{
	size_t	i;

	i = 0;
	if (lenght == 0)
		return (0);
	while (i + 1 < lenght && (first[i] == second[i])
		&& (first[i]) && (second[i]))
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
