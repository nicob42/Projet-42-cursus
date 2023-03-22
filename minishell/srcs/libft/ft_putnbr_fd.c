/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:13:12 by nbechard          #+#    #+#             */
/*   Updated: 2022/09/29 09:13:12 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_neg(int n, int fd)
{
	ft_putchar_fd('-', fd);
	if (n == -2147483648)
	{
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	else
		n *= -1;
	return (n);
}

void	ft_calnbr(int n, int i, char c, int fd)
{
	char	tab[10];

	if (n < 0)
		n = ft_neg(n, fd);
	while (n > 0)
	{
		tab[i] = n % 10;
		n = n / 10;
		i ++;
	}
	i --;
	while (i >= 0)
	{
		c = tab[i];
		ft_putchar_fd(c + 48, fd);
		i --;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	d;
	int		i;

	c = 0;
	d = 45;
	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_calnbr(n, i, c, fd);
}
