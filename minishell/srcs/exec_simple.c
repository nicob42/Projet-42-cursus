/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:55:47 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:55:59 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_clean_quote(char *str, int i)
{
	i = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	ft_clean_args(t_program *program, int i, int j)
{
	while (program->cmd_args[i])
	{
		j = 0;
		while (program->cmd_args[i][j])
		{
			if (program->cmd_args[i][j] == '\n')
				program->cmd_args[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	ft_fill_space(t_program *program, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			while (str[i] != 34 && str[i] != 39)
			{
				if (str[i] == ' ')
					str[i] = '\n';
				i++;
			}
		}
		i++;
	}
	str = ft_clean_quote(str, 0);
	program->cmd_args = ft_split(str, ' ');
	ft_clean_args(program, 0, 0);
}

char	*ft_get_cmd(t_program *program, char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(command, 0) == 0)
		{
			program->statu = 0;
			return (command);
		}
		free (command);
		paths++;
	}
	program->statu = 127;
	return (NULL);
}

int	*ft_exec_simple(t_program *program, char *line, char **envp)
{
	if (!ft_simplequote(line, 0) || !ft_doublequote(line, 0))
		ft_fill_space(program, line, 0);
	else
		program->cmd_args = ft_split(line, ' ');
	program->cmd = ft_get_cmd(program, program->cmd_paths,
			program->cmd_args[0]);
	execve(program->cmd, program->cmd_args, envp);
	if (!program->cmd)
	{
		ft_error("zsh : command not found : ", program->cmd_args[0]);
		exit (0);
	}
	ft_free_child(program);
	exit (2);
}
