/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:58:33 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:58:42 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_fill_str(char *line, char *str, int i)
{
	int	j;

	j = 0;
	i++;
	while (line[i] && (line[i] != ' ' || line[i] != '"'))
	{
		str[j] = line[i];
		i++;
		j++;
	}
	return (str);
}

void	ft_fill(t_program *program, int j)
{
	int	i;
	int	ii;

	i = 0;
	ii = program->tmp_len;
	program->tmp_len = 0;
	while (program->export[j][i] && program->export[j][i] != '=')
		i++;
	i++;
	while (program->export[j][i])
	{
		program->tmp_env[ii] = program->export[j][i];
		i++;
		ii++;
		program->tmp_len++;
	}
}

void	ft_fill_status(t_program *program, int j, int i)
{
	j = program->tmp_len;
	while (program->status[i])
	{
		program->tmp_env[j] = program->status[i];
		i++;
		j++;
		program->tmp_len++;
	}
}

int	ft_true(t_program *program, char *line, int i, int j)
{
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * 100);
	str = ft_fill_str(line, str, i);
	while (j < program->export_l)
	{
		if (!ft_check_corresp(program->export[j], str))
		{
			ft_fill(program, j);
			free(str);
			return (0);
		}
		j++;
	}
	if (line[i + 1] == '?')
	{
		ft_fill_status(program, 0, 0);
		return (0);
	}
	free(str);
	return (1);
}
