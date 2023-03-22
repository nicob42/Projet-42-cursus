/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:53:27 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:53:36 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	ft_tmp(t_program *program, char **envp)
{
	program->paths = ft_find_path(envp);
	program->cmd_paths = ft_split(program->paths, ':');
}

int	ft_read_line(t_program *program, char *line, char **envp)
{
	ft_parse(program, line, envp);
	return (0);
}

int	ft_isempty(char *str)
{
	while (*str)
		if (!ft_ispace(*(str++)))
			return (0);
	return (1);
}

void	ft_process(t_program *program, char **envp)
{
	char	*line;
	int		i;

	ft_tmp(program, envp);
	while (1)
	{
		ft_prompt(program);
		if (!program->prompt.inv)
			break ;
		ft_update_status(program, program->statu);
		line = readline(program->prompt.inv);
		if (!line)
			break ;
		if (!ft_isempty(line))
		{
			i = ft_exit(program, line, "exit");
			add_history(line);
			if (i == 0)
				exit (0);
			else if (i != 2)
				ft_read_line(program, line, envp);
			ft_echo(program, line);
		}
		ft_ending_free(program, line);
	}
}
