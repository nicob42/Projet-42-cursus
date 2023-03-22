/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:55:22 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:55:30 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **str, int i)
{
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	ft_check_args(char *s)
{
	int		i;
	int		check;
	char	**space;
	char	**tab;

	check = 0;
	i = 0;
	space = ft_split(s, ' ');
	tab = ft_split(s, '\t');
	while (space[i++])
		check++;
	i = 0;
	while (tab[i++])
		check++;
	if (check > 3)
	{
		ft_free_split (space, 0);
		ft_free_split (tab, 0);
		return (0);
	}
	ft_free_split (space, 0);
	ft_free_split (tab, 0);
	return (1);
}

void	ft_free(t_program *program, int i)
{
	while (i <= program->export_l)
	{
		free (program->export[i]);
		i++;
	}
	free (program->tmp_env);
	free (program->prompt.inv);
	free (program->status);
	free (program->path);
	free (program->export);
	ft_free_split (program->cmd_paths, 0);
}

int	ft_exit(t_program *program, char *s1, char *s2)
{
	int	i;

	(void)program;
	i = 0;
	while (i <= 3)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (!ft_check_args(s1))
	{
		ft_error("exit : too many arguments.", "");
		return (2);
	}
	ft_free(program, 0);
	return (0);
}
