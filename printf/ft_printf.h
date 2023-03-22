/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechard <nbechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:50:07 by nbechard          #+#    #+#             */
/*   Updated: 2022/03/09 09:05:49 by nbechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	ischar(t_print *arg_count);
void	isstr(t_print *arg_count);
void	isptr(t_print *arg_count);
void	ishex(t_print *arg_count, char c);
void	isint(t_print *arg_count);
void	isunsignedint(t_print *arg_count);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);

#endif
