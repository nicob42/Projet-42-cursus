/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:55:03 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:55:12 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printf_export(t_program *program, int x, int j)
{
	int	i;

	i = 0;
	while (i < program->export_l)
	{
		if (x == 1)
			dup2(program->tube[1], 1);
		if (program->export[i] != NULL && j == 1)
			printf("%s\n", program->export[i]);
		i++;
	}
	if (x == 1)
	{
		close(program->tube[0]);
		exit (0);
	}
}

void	ft_refill_1(t_program *program, char *str)
{
	int	i;

	i = 0;
	program->export[program->export_l] = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		program->export[program->export_l][i] = str[i];
		i++;
	}
	program->export[program->export_l][i] = '\0';
	program->export_l++;
}

void	ft_refill_2(t_program *program, char *str)
{
	int		i;

	i = 0;
	program->export[program->export_l] = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		program->export[program->export_l][i] = str[i];
		i++;
	}
	program->export[program->export_l][i++] = '=';
	program->export[program->export_l][i++] = '"';
	program->export[program->export_l][i++] = '"';
	program->export[program->export_l][i] = '\0';
	program->export_l++;
}

int	ft_refill_export(t_program *program, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			ft_refill_1(program, str);
			return (0);
		}
		i++;
	}
	ft_refill_2(program, str);
	return (0);
}

void	ft_export(t_program *program, char *line, int x)
{
	char	**pipe;
	char	**tmp;
	int		i;

	i = 1;
	if (x == 1)
	{
		pipe = ft_split(line, '|');
		tmp = ft_split(pipe[0], ' ');
	}
	else
		tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i == 1 || x == 1)
		ft_printf_export(program, x, i);
	i = 1;
	while (tmp[i])
	{
		ft_refill_export(program, tmp[i]);
		i++;
	}
}
