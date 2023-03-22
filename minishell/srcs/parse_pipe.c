/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:51:15 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:51:42 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isit_builtin_pipe(t_program *program, char *line, char **envp)
{
	if (!ft_check_corresp_args(line, "cd"))
		ft_exec_cd(program, line, 1);
	else if (!ft_check_corresp(line, "export"))
		ft_exec_export(program, line, 1, envp);
	else if (!ft_check_corresp(line, "unset"))
		ft_exec_unset(program, line, 1, envp);
	else if (!ft_check_corresp(line, "pwd"))
		ft_exec_pwd(program, line, 1, envp);
	else if (!ft_check_corresp(line, "env"))
		ft_exec_env(program, line, 1, envp);
	if (!ft_check_corresp_args(line, "cd") || !ft_check_corresp(line, "export")
		|| !ft_check_corresp(line, "unset") || !ft_check_corresp(line, "pwd")
		|| !ft_check_corresp(line, "env"))
		return (0);
	return (1);
}

int	ft_parse_pipe_tmp(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '<' || line[i] == '>')
			&& (!ft_simplequote_csearch(line, i, '<')
				|| !ft_simplequote_csearch(line, i, '>')
				|| !ft_doublequote_csearch(line, i, '<')
				|| !ft_doublequote_csearch(line, i, '>')))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_pipe(t_program *program, char *line, char **envp)
{
	char	*tmp;

	if (!ft_parse_pipe_tmp(line))
		return (0);
	if (!ft_isit_builtin_pipe(program, line, envp))
		return (0);
	else
	{
		program->cmd_args = ft_split(line, ' ');
		tmp = ft_get_cmd(program, program->cmd_paths, program->cmd_args[0]);
		free (tmp);
		ft_free_split (program->cmd_args, 0);
		program->pid1 = fork();
		if (program->pid1 == 0)
			ft_exec_pipe(program, line, envp);
	}
	waitpid(program->pid1, NULL, 0);
	return (0);
}
