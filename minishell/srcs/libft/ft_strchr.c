/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:13:16 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:13:23 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int x)
{
	return (ft_memchr(str, x, ft_strlen((char *)str) + 1));
}
