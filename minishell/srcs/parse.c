/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:53:05 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:53:16 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_simplequote(char *str, int i)
{
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == 39)
			check++;
		i++;
	}
	if (check != 0 && check % 2 == 0)
		return (0);
	return (1);
}

int	ft_doublequote(char *str, int i)
{
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == 34)
			check++;
		i++;
	}
	if (check != 0 && check % 2 == 0)
		return (0);
	return (1);
}

int	ft_doublequote_csearch(char *str, int i, char c)
{
	int	check;

	check = 0;
	i = 0;
	if (!ft_doublequote(str, i))
	{
		while (str[i])
		{
			if (str[i] == 34)
			{
				i++;
				while (str[i] != 34)
					i++;
			}
			else if (str[i] == c)
				check++;
			i++;
		}
	}
	else if (!ft_csearch(str, c) && ft_simplequote(str, c))
		return (0);
	if (check > 0)
		return (0);
	return (1);
}

int	ft_simplequote_csearch(char *str, int i, char c)
{
	int	check;

	check = 0;
	i = 0;
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
	else if (!ft_csearch(str, c) && ft_doublequote(str, c))
		return (0);
	if (check > 0)
		return (0);
	return (1);
}

int	ft_parse(t_program *program, char *line, char **envp)
{
	char	**tmp;
	int		i;

	i = 0;
	line = ft_env_var(program, line);
	tmp = ft_split(line, ' ');
	while (tmp[i])
	{
		if (!ft_csearch(tmp[i], '|') && (!ft_simplequote_csearch(line, i, '|')
				|| !ft_doublequote_csearch(line, i, '|')))
		{
			ft_parse_pipe(program, line, envp);
			ft_free_split (tmp, 0);
			return (0);
		}
		i++;
	}
	ft_parse_simple(program, line, envp);
	ft_free_split (tmp, 0);
	return (0);
}
