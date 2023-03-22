/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:58:10 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:58:14 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_program *program, char *line)
{
	(void)program;
	if (!ft_check_corresp_bis(line, "echo -n"))
		printf("\n");
}

void	ft_update_status(t_program *program, int i)
{
	if (i == 0)
	{
		program->status = malloc(sizeof(char) * 2);
		program->status[0] = '0';
		program->status[1] = '\0';
	}
	else if (i == 1)
	{
		program->status = malloc(sizeof(char) * 2);
		program->status[0] = '1';
		program->status[1] = '\0';
	}
	else if (i == 127)
	{
		program->status = malloc(sizeof(char) * 4);
		program->status[0] = '1';
		program->status[1] = '2';
		program->status[2] = '7';
		program->status[3] = '\0';
	}
	program->tmp_env = malloc(sizeof(char) * 1000);
}

void	ft_error(char *str, char *line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	ft_putstr_fd(line, 2);
	write(2, "\n", 1);
}

void	ft_update_pwd(t_program *program)
{
	program->tmp_path = malloc(100);
	getcwd(program->tmp_path, 100);
}

void	ft_ending_free(t_program *prog, char *line)
{
	ft_process_free(prog);
	free (line);
	free (prog->prompt.inv);
}
