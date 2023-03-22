/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:54:18 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:54:29 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_unset(t_program *program, char **tmp)
{
	int	i;

	i = 0;
	while (i < program->export_l)
	{
		if (!ft_check_corresp(program->export[i], tmp[1]))
		{
			program->export[i] = NULL;
			free(program->export[i]);
			break ;
		}
		i++;
	}
}

void	ft_unset(t_program *program, char *line, int x, char **envp)
{
	char	**tmp;

	(void)envp;
	tmp = ft_split(line, ' ');
	if (tmp[1] != NULL)
		ft_clean_unset(program, tmp);
	if (x == 1)
	{
		dup2(program->tube[1], 1);
		close(program->tube[0]);
		exit (0);
	}
	free(tmp);
}
