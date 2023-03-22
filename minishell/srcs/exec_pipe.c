/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:56:11 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:56:21 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipes(t_program *program)
{
	close(program->tube[0]);
	close(program->tube[1]);
}

void	ft_child2(t_program *program, char **envp)
{
	dup2(program->tube[0], 0);
	close(program->tube[1]);
	ft_exec_simple(program, program->tmp[1], envp);
	ft_free_child(program);
}

void	ft_child1(t_program *program, char **envp)
{
	dup2(program->tube[1], 1);
	close(program->tube[0]);
	ft_exec_simple(program, program->tmp[0], envp);
	ft_free_child(program);
}

int	ft_exec_pipe(t_program *program, char *line, char **envp)
{
	if (pipe(program->tube) < 0)
	{
		ft_error("Pipe error.", "");
		return (0);
	}
	program->tmp = ft_split(line, '|');
	program->child1 = fork();
	if (program->child1 == 0)
		ft_child1(program, envp);
	program->child2 = fork();
	if (program->child2 == 0)
		ft_child2(program, envp);
	ft_close_pipes(program);
	waitpid(program->child1, NULL, 0);
	waitpid(program->child2, NULL, 0);
	free (program->tmp);
	return (0);
}
