/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_corresp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:56:04 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 08:56:04 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_corresp(char *s1, char *s2)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (s2[i])
	{
		check = 0;
		if (s1[j] == ' ' || s1[j] == '\t')
		{
			j++;
			check++;
		}
		if (check == 0)
		{
			if (s1[j] != s2[i])
				return (1);
			j++;
			i++;
		}
	}
	return (0);
}

int	ft_check_corresp_bis(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (s1[j] == ' ' || s1[j] == '\t')
			j++;
		if (s2[i] == ' ' || s2[i] == '\t')
			i++;
		if (s1[j] != s2[i] && (s1[j] != ' ' || s1[j] != '\t')
			&& (s2[i] != ' ' || s2[i] != '\t'))
			return (1);
		j++;
		i++;
	}
	return (0);
}
