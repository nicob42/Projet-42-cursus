/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:00:13 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 09:00:25 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_pipe(t_program *program, char *line, char **envp)
{
	if (pipe(program->tube) < 0)
	{
		ft_error("Pipe error.", "");
		return (0);
	}
	program->tmp = ft_split(line, '|');
	program->child1 = fork();
	if (program->child1 == 0)
		ft_export(program, line, 1);
	program->child2 = fork();
	if (program->child2 == 0)
		ft_child2(program, envp);
	ft_close_pipes(program);
	waitpid(program->child1, NULL, 0);
	waitpid(program->child2, NULL, 0);
	return (0);
}

int	ft_pwd_pipe(t_program *program, char *line, char **envp)
{
	if (pipe(program->tube) < 0)
	{
		ft_error("Pipe error.", "");
		return (0);
	}
	program->tmp = ft_split(line, '|');
	program->child1 = fork();
	if (program->child1 == 0)
		ft_exec_pwd(program, line, 2, envp);
	program->child2 = fork();
	if (program->child2 == 0)
		ft_child2(program, envp);
	ft_close_pipes(program);
	waitpid(program->child1, NULL, 0);
	waitpid(program->child2, NULL, 0);
	free (program->tmp);
	return (0);
}

int	ft_unset_pipe(t_program *program, char *line, char **envp)
{
	if (pipe(program->tube) < 0)
	{
		ft_error("Pipe error.", "");
		return (0);
	}
	program->tmp = ft_split(line, '|');
	program->child2 = fork();
	if (program->child2 == 0)
		ft_child2(program, envp);
	ft_close_pipes(program);
	waitpid(program->child2, NULL, 0);
	free (program->tmp);
	return (0);
}

int	ft_env_pipe(t_program *program, char *line, char **envp)
{
	if (pipe(program->tube) < 0)
	{
		ft_error("Pipe error.", "");
		return (0);
	}
	program->tmp = ft_split(line, '|');
	program->child1 = fork();
	if (program->child1 == 0)
		ft_exec_env_pipe(program, line, envp);
	program->child2 = fork();
	if (program->child2 == 0)
		ft_child2(program, envp);
	ft_close_pipes(program);
	waitpid(program->child1, NULL, 0);
	waitpid(program->child2, NULL, 0);
	free (program->tmp);
	return (0);
}
