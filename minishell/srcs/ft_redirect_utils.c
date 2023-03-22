/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:48:42 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:48:56 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dupexec1(t_program *program, char *line, char **envp, int fd)
{
	program->child1 = fork();
	if (program->child1 == 0)
	{
		dup2(fd, 1);
		ft_exec_simple(program, line, envp);
	}
	waitpid(program->child1, NULL, 0);
	close(fd);
}

void	ft_dupexec0(t_program *program, char *line, char **envp, int fd)
{
	program->child1 = fork();
	if (program->child1 == 0)
	{
		dup2(fd, 0);
		ft_exec_simple(program, line, envp);
	}
	waitpid(program->child1, NULL, 0);
	close(fd);
}

void	exec1(t_program *program, char *line, char **envp)
{
	program->child1 = fork();
	if (program->child1 == 0)
		ft_exec_simple(program, line, envp);
	waitpid(program->child1, NULL, 0);
	while (1)
	{
		close(program->fd);
		unlink("Z");
		break ;
	}
}

void	catisboring(t_program *program)
{
	program->count = 0;
	lseek(program->fd, 0, 0);
	program->ret = read(program->fd, program->buf, BUFFER_SIZE);
	while (program->ret != 0)
	{
		program->count += 1;
		program->buf[program->ret] = '\0';
		if (program->count > BUFFER_SIZE)
		{
			program->ret = 0;
			printf("Erreur de saisie\n");
			break ;
		}
		ft_putstr(program->buf);
		program->ret = read(program->fd, program->buf, BUFFER_SIZE);
		break ;
	}
}

void	closeunlink(t_program *program)
{
	while (1)
	{
		close(program->fd);
		unlink("Z");
		break ;
	}
}
