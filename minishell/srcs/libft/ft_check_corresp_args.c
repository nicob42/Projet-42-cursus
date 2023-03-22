/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_corresp_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:54:45 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 08:54:45 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_corresp_args(char *s1, char *s2)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (s2[j])
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
