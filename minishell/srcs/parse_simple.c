/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:52:44 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:52:53 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isit_builtin(t_program *program, char *line, char **envp)
{
	if (!ft_check_corresp_args(line, "cd"))
		ft_exec_cd(program, line, 0);
	else if (!ft_check_corresp(line, "export"))
		ft_exec_export(program, line, 0, envp);
	else if (!ft_check_corresp(line, "unset"))
		ft_exec_unset(program, line, 0, envp);
	else if (!ft_check_corresp(line, "pwd"))
		ft_exec_pwd(program, line, 0, envp);
	else if (!ft_check_corresp(line, "env"))
		ft_exec_env(program, line, 0, envp);
	if (!ft_check_corresp_args(line, "cd") || !ft_check_corresp(line, "export")
		|| !ft_check_corresp(line, "unset") || !ft_check_corresp(line, "pwd")
		|| !ft_check_corresp(line, "env"))
		return (0);
	return (1);
}

int	ft_parse_simple_tmp(char *line)
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

static int	ft_parse_simple_alt(t_program *program, char *line, char **envp)
{
	int		stat;
	char	*tmp;

	if (!ft_parse_simple_tmp(line))
		return (0);
	if (!ft_isit_builtin(program, line, envp))
		return (0);
	else
	{
		program->cmd_args = ft_split(line, ' ');
		tmp = ft_get_cmd(program, program->cmd_paths, program->cmd_args[0]);
		free (tmp);
		free(program->cmd_args);
		program->pid1 = fork();
		if (program->pid1 == 0)
			ft_exec_simple(program, line, envp);
	}
	waitpid(program->pid1, &stat, 0);
	if (stat != 0)
		program->statu = 1;
	return (0);
}

int	ft_parse_simple(t_program *program, char *line, char **envp)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '>' || line[i] == '<')
		{
			ft_redirection(program, line, &line[i], envp);
			return (0);
		}
		i++;
	}
	return (ft_parse_simple_alt(program, line, envp));
}
