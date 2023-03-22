/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:59:45 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:59:55 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_cd(t_program *program, char *line, int i)
{
	char	**path;

	if (!ft_check_corresp_bis("cd -", line))
		chdir(program->tmp_path);
	else if (!ft_check_corresp("cd", line)
		|| !ft_check_corresp_bis("cd ~", line))
	{
		ft_update_pwd(program);
		chdir(program->path);
	}
	else
	{
		ft_update_pwd(program);
		if (i == 0)
		{
			path = ft_split(line, ' ');
			chdir(path[1]);
			free (path);
		}
	}
}

void	ft_exec_export(t_program *program, char *line, int i, char **envp)
{
	if (i == 0)
		ft_export(program, line, i);
	else
		ft_export_pipe(program, line, envp);
}

void	ft_exec_unset(t_program *program, char *line, int i, char **envp)
{
	if (i == 0)
		ft_unset(program, line, i, envp);
	else
		ft_unset_pipe(program, line, envp);
}

void	ft_exec_pwd(t_program *program, char *line, int i, char **envp)
{
	char	s[100];

	(void)program;
	(void)line;
	if (i == 0)
		printf("%s\n", getcwd(s, 100));
	else if (i == 1)
		ft_pwd_pipe(program, line, envp);
	else
	{
		dup2(program->tube[1], 1);
		printf("%s\n", getcwd(s, 100));
		close(program->tube[0]);
		exit (0);
	}
}

void	ft_exec_env(t_program *program, char *line, int i, char **envp)
{
	if (i == 0)
		ft_exec_env_simple(program, line, envp);
	else
		ft_env_pipe(program, line, envp);
}
