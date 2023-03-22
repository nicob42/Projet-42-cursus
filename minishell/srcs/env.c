/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:59:25 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:59:34 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_env_simple(t_program *program, char *line, char **envp)
{
	int	tmp;

	tmp = program->env;
	program->pid1 = fork();
	if (program->pid1 == 0)
		ft_exec_simple(program, line, envp);
	waitpid(program->pid1, NULL, 0);
	while (tmp < program->export_l)
	{
		if (program->export[tmp] != NULL)
			printf("%s\n", program->export[tmp]);
		tmp++;
	}
}

void	ft_exec_env_pipe(t_program *program, char *line, char **envp)
{
	int	tmp;

	(void)line;
	dup2(program->tube[1], 1);
	close(program->tube[0]);
	tmp = program->env;
	while (tmp < program->export_l)
	{
		if (program->export[tmp] != NULL)
			printf("%s\n", program->export[tmp]);
		tmp++;
	}
	ft_exec_simple(program, program->tmp[0], envp);
}
