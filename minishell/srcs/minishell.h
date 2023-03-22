/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusso <alrusso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:49:41 by alrusso           #+#    #+#             */
/*   Updated: 2022/09/29 08:49:51 by alrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 2000

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_prompt
{
	char		*inv;
	char const	*user;
	char const	*host;
	char const	*aux;
	char const	*rep;
}	t_prompt;

typedef struct s_program
{
	pid_t			pid1;
	pid_t			child1;
	pid_t			child2;
	int				tube[2];
	int				export_l;
	char			**export;
	char			**tmp;
	char			*path;
	char			*paths;
	char			**cmd_paths;
	char			**cmd_args;
	char			*cmd;
	int				i;
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	int				fd;
	unsigned int	octet;
	char			**s1;
	char			**s2;
	char			**str;
	unsigned int	count;
	t_prompt		prompt;
	int				t;
	int				env;
	int				tmp_len;
	int				statu;
	char			*status;
	char			*tmp_env;
	char			*tmp_path;
}	t_program;

int		ft_parse_simple(t_program *program, char *line, char **envp);
void	ft_process(t_program *program, char **envp);
int		*ft_exec_simple(t_program *program, char *line, char **envp);
int		ft_exit(t_program *program, char *s1, char *s2);
void	ft_free_child(t_program *program);
void	ft_free_parent(t_program *program);
void	ft_error(char *str, char *line);
void	ft_prompt(t_program *program);
void	ft_exec_cd(t_program *program, char *line, int i);
void	ft_exec_export(t_program *program, char *line, int i, char **envp);
void	ft_exec_unset(t_program *program, char *line, int i, char **envp);
void	ft_exec_pwd(t_program *program, char *line, int i, char **envp);
int		ft_parse_pipe(t_program *program, char *line, char **envp);
char	*ft_get_cmd(t_program *program, char **paths, char *cmd);
int		ft_exec_pipe(t_program *program, char *line, char **envp);
int		ft_exec_builtin_pipe(t_program *program, char *line, char **envp);
void	ft_child2(t_program *program, char **envp);
void	ft_close_pipes(t_program *program);
void	ft_export(t_program *program, char *line, int i);
int		ft_export_pipe(t_program *program, char *line, char **envp);
int		ft_pwd_pipe(t_program *program, char *line, char **envp);
void	ft_unset(t_program *program, char *line, int x, char **envp);
int		ft_unset_pipe(t_program *program, char *line, char **envp);
int		ft_parse(t_program *program, char *line, char **envp);
int		ft_one_suppremum(t_program *program, char *line, char **envp);
int		ft_one_infinum(t_program *program, char *line, char **envp);
int		ft_two_suppremum(t_program *program, char *line, char **envp);
int		ft_two_infinum(t_program *program, char *line, char **envp);
void	ft_dupexec1(t_program *program, char *line, char **envp, int fd);
void	ft_dupexec0(t_program *program, char *line, char **envp, int fd);
void	catisboring(t_program *program);
void	exec1(t_program *program, char *line, char **envp);
void	closeunlink(t_program *program);
int		ft_redirection(t_program *program, char *line, char *spot, char **envp);
int		ft_simplequote_csearch(char *str, int i, char c);
int		ft_doublequote_csearch(char *str, int i, char c);
int		ft_simplequote(char *str, int i);
int		ft_doublequote(char *str, int i);
char	*ft_clean_quote(char *str, int i);
char	*ft_env_var(t_program *program, char *line);
void	ft_update_pwd(t_program *program);
void	ft_exec_env(t_program *program, char *line, int i, char **envp);
int		ft_env_pipe(t_program *program, char *line, char **envp);
void	ft_exec_env_simple(t_program *program, char *line, char **envp);
void	ft_exec_env_pipe(t_program *program, char *line, char **envp);
int		ft_true(t_program *program, char *line, int i, int j);
void	ft_update_status(t_program *program, int i);
void	ft_process_free(t_program *program);
void	ft_echo(t_program *program, char *line);
void	ft_free_split(char **str, int i);
void	ft_ending_free(t_program *prog, char *line);
void	ft_signal_handler(int sig);
void	rl_replace_line(const char *i, int y);

#endif
