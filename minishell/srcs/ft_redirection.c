/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:47:59 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:48:19 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_one_suppremum(t_program *program, char *line, char **envp)
{
	program->i = 0;
	program->s1 = ft_split(line, '>');
	program->s2 = ft_split(program->s1[1], ' ');
	while (program->s2[program->i] != NULL)
	{
		program->fd = open(program->s2[program->i], \
			O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (program->fd == -1)
			program->i += 1;
		else
			break ;
		program->i += 1;
	}
	ft_dupexec1(program, program->s1[0], envp, program->fd);
	return (0);
}

int	ft_one_infinum(t_program *program, char *line, char **envp)
{
	program->i = 0;
	program->s1 = ft_split(line, '<');
	program->s2 = ft_split(program->s1[1], ' ');
	while (program->s2[program->i] != NULL)
	{
		program->fd = open(program->s2[program->i], O_RDONLY);
		if (program->fd == -1)
			ft_putstr_fd("no such file or directory\n", 2);
		else
		{
			ft_dupexec0(program, program->s1[0], envp, program->fd);
			break ;
		}
		program->i += 1;
	}
	return (0);
}

int	ft_two_suppremum(t_program *program, char *line, char **envp)
{
	program->i = 0;
	program->s1 = ft_split(line, '>');
	program->s2 = ft_split(program->s1[1], ' ');
	while (program->s2[program->i] != NULL)
	{
		program->fd = open(program->s2[program->i], \
			O_RDWR | O_CREAT | O_APPEND, 0777);
		if (program->fd == -1)
			program->i += 1;
		else
			break ;
		program->i += 1;
	}
	ft_dupexec1(program, program->s1[0], envp, program->fd);
	return (0);
}

int	ft_two_infinum(t_program *program, char *line, char **envp)
{
	program->str = malloc(10000);
	program->i = 0;
	program->s1 = ft_split(line, '<');
	if (!program->s1[1])
		program->s1[1] = ft_strdup("");
	program->fd = open("Z", O_CREAT | O_RDWR | O_APPEND | O_TRUNC, S_IRWXU);
	while (1)
	{
		program->str[program->i] = readline("heredoc>");
		if (ft_check_corresp_redirect(program->str[program->i], program->s1[1]))
			ft_putendl_fd(program->str[program->i], program->fd);
		else if (ft_strlen(program->str[program->i]) \
			== ft_strlen(program->s1[1]))
		{
			if (ft_check_corresp_redirect(program->s1[0], "cat") == 0)
			{
				catisboring(program);
				closeunlink(program);
				break ;
			}
			exec1(program, program->s1[0], envp);
			break ;
		}
	}
	return (0);
}

int	ft_redirection(t_program *program, char *line, char *spot, char **envp)
{
	if (ft_strncmp(spot, ">>", 2) == 0)
		ft_two_suppremum(program, line, envp);
	else if (ft_strncmp(spot, "<<", 2) == 0)
		ft_two_infinum(program, line, envp);
	else if (ft_strncmp(spot, ">", 1) == 0)
		ft_one_suppremum(program, line, envp);
	else if (ft_strncmp(spot, "<", 1) == 0)
		ft_one_infinum(program, line, envp);
	return (0);
}
