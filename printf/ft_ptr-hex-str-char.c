/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr-hex-str-char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 07:53:08 by nbechard          #+#    #+#             */
/*   Updated: 2022/03/09 09:05:55 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbrlen(unsigned long nbr, int *len)
{
	char	*str;

	while (nbr >= 16)
	{
		nbr = nbr / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

void	ishex(t_print *arg_count, char c)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	nbr = va_arg(arg_count->args, unsigned int);
	len = 1;
	str = nbrlen(nbr, &len);
	len--;
	while (len >= 0)
	{
		if (nbr % 16 < 10)
			str[len] = '0' + (nbr % 16);
		else if (c == 'x')
			str[len] = 'a' - 10 + (nbr % 16);
		else if (c == 'X')
			str[len] = 'A' - 10 + (nbr % 16);
		nbr = nbr / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	isptr(t_print *arg_count)
{
	int				len;
	char			*str;
	unsigned long	nbr;

	nbr = va_arg(arg_count->args, unsigned long);
	len = 1;
	str = nbrlen(nbr, &len);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	len--;
	while (len >= 0)
	{
		if (nbr % 16 < 10)
			str[len] = '0' + (nbr % 16);
		else
			str[len] = 'a' + (nbr % 16) - 10;
		nbr = nbr / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ischar(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}

void	isstr(t_print *arg_count)
{
	char	*str;
	int		len;

	str = va_arg(arg_count->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arg_count->counter += len;
	}
}
