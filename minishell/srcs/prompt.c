/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:53:52 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:54:05 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_rep(t_program *program)
{
	program->prompt.rep = program->prompt.aux + ft_strlen(program->prompt.aux);
	while (program->prompt.rep > program->prompt.aux
		&& *program->prompt.rep != '/')
		program->prompt.rep--;
	program->prompt.rep++;
}

void	ft_aux(t_program *program)
{
	program->prompt.aux = getenv("PWD");
	if (program->prompt.aux == NULL)
	{
		program->prompt.aux = "";
	}
}

void	ft_host(t_program *program)
{
	program->prompt.host = getenv("HOSTNAME");
	if (program->prompt.host == NULL)
	{
		program->prompt.host = "";
	}
}

void	ft_user(t_program *program)
{
	program->prompt.user = getenv("USERNAME");
	if (program->prompt.user == NULL)
	{
		program->prompt.user = getenv("USER");
		if (program->prompt.user == NULL)
		{
			program->prompt.user = "";
		}
	}
}

void	ft_prompt(t_program *program)
{
	program->prompt.inv = NULL;
	ft_user(program);
	ft_host(program);
	ft_aux(program);
	ft_rep(program);
	program->prompt.inv = malloc(ft_strlen(program->prompt.user) + \
		ft_strlen(program->prompt.host) + \
		ft_strlen(program->prompt.rep) + 7);
	if (program->prompt.inv != NULL)
	{
		ft_strcpy(program->prompt.inv, "[");
		ft_strcat(program->prompt.inv, program->prompt.user);
		ft_strcat(program->prompt.inv, "@");
		ft_strcat(program->prompt.inv, program->prompt.host);
		ft_strcat(program->prompt.inv, " ");
		ft_strcat(program->prompt.inv, program->prompt.rep);
		ft_strcat(program->prompt.inv, "]");
		ft_strcat(program->prompt.inv, "$");
		ft_strcat(program->prompt.inv, " ");
	}
}
