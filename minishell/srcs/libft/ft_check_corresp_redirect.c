/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_corresp_redirect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:55:36 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 08:55:36 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_corresp_redirect(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i])
	{
		if (s1[j] != s2[i])
			return (1);
		j++;
		i++;
	}
	return (0);
}
