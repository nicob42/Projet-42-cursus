/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:59:08 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:59:17 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_var(char *str, int i, char c)
{
	int	check;

	check = 0;
	if (!ft_simplequote(str, i))
	{
		while (str[i])
		{
			if (str[i] == 39)
			{
				i++;
				while (str[i] != 39)
					i++;
			}
			if (str[i] == c)
				check++;
			i++;
		}
	}
	else
		return (0);
	if (check > 0)
		return (0);
	return (1);
}

void	ft_false(t_program *program, char *line, int i)
{
	while (line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		i++;
		program->tmp_len++;
	}
}

char	*ft_find_var(t_program *program, char *line, int i, int j)
{
	while (line[i])
	{
		program->tmp_len = j;
		if (line[i] == '$' && !ft_true(program, line, i, j))
		{
			while (line[i] && (line[i] != ' ' || line[i] != '"'))
				i++;
			j = j + program->tmp_len;
		}
		else if (line[i] == '$')
			ft_false(program, line, i);
		else
			program->tmp_env[j] = line[i];
		j++;
		i++;
	}
	return (program->tmp_env);
}

char	*ft_env_var(t_program *program, char *line)
{
	if (!ft_csearch(line, '$') && !ft_parse_var(line, 0, '$'))
	{
		line = ft_find_var(program, line, 0, 0);
	}
	return (line);
}
