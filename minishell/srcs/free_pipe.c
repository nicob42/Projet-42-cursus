/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:54:47 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:54:54 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process_free(t_program *program)
{
	free(program->tmp_env);
	free(program->status);
}

void	ft_free_parent(t_program *program)
{
	int	i;

	i = 0;
	while (program->cmd_paths[i])
	{
		free(program->cmd_paths[i]);
		i++;
	}
	free(program->cmd_paths);
}

void	ft_free_child(t_program *program)
{
	int	i;

	i = 0;
	while (program->cmd_args[i])
	{
		free(program->cmd_args[i]);
		i++;
	}
	free(program->cmd_args);
	free(program->cmd);
}
