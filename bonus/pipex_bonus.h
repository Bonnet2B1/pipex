/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:55:15 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/21 19:38:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pip
{
	int		i;
	char	**argv;
	char	**env;
	char	*stdin;
	char	*cmd1;
	char	*cmd2;
	char	*stdout;
	char	**paths;
	char	*cmd_path;
	char	**cmd1_split;
	char	**cmd2_split;
	int		pipe_fd[2];
	int		pid1;
	int		pid2;
}			t_pip;

//	parser
void		parser_bonus(t_pip *p, int argc, char **argv, char **env);

//	utils
t_pip		*pip_init_to_null(t_pip *p);
t_pip		*pip_init(t_pip *p, int argc, char **argv, char **env);
char		**ft_split(const char *s, char c);
char		**ft_split_w_slash(const char *s, char c);
int			ft_isascii(int c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		**get_paths(char **env);
char		*find_cmd_path(t_pip *p, char *cmd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
void		free_print_exit(t_pip *p, char *str);
void		freeall(t_pip *p);
char		**free_tab(char **tab);

//	temp
void		print_path(t_pip *p);

#endif