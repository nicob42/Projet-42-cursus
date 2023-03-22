/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:00:31 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 09:00:31 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		l = 1;
	else if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		*str;
	int			i;

	nbr = n;
	i = ft_len(nbr);
	str = (char *)malloc (sizeof(char) * (ft_len(nbr) + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
