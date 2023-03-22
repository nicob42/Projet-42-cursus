/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int-unsignedint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 08:15:41 by nbechard          #+#    #+#             */
/*   Updated: 2022/03/09 09:05:39 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*uitoa(unsigned int nbr)
{
	char	*str;
	int		len;

	len = nbrlen(nbr);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

void	isint(t_print *arg_count)
{
	char	*str;
	int		rslt;

	rslt = va_arg(arg_count->args, int);
	str = ft_itoa(rslt);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}

void	isunsignedint(t_print *arg_count)
{
	char			*str;
	unsigned int	rslt;

	rslt = va_arg(arg_count->args, unsigned int);
	str = uitoa(rslt);
	ft_putstr_fd(str, 1);
	arg_count->counter += ft_strlen(str);
	free(str);
}
