/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:49:17 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:49:27 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_export(t_program *program, char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i + 1])
	{
		j = 0;
		while (envp[i][j])
		{
			program->export[i][j] = envp[i][j];
			j++;
		}
		program->export[i][j] = '\0';
		i++;
	}
}

void	ft_init(t_program *program, char **envp)
{
	int		i;
	int		j;

	program->path = malloc(100);
	i = 0;
	while (envp[i])
		i++;
	program->export_l = i - 1;
	program->env = program->export_l;
	i = 0;
	program->export = malloc(sizeof(char *) * 10000);
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
			j++;
		program->export[i] = malloc(sizeof(char) * j);
		i++;
	}
	program->export[i] = NULL;
	ft_fill_export(program, envp);
	getcwd(program->path, 100);
}

void	ft_signal_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_program	program;

	(void)argc;
	(void)argv;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	program.statu = 0;
	ft_init(&program, envp);
	ft_process(&program, envp);
	return (0);
}
