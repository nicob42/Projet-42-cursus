/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:08:19 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:08:26 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 97 && i <= 122)
		i -= 32;
	return (i);
}
