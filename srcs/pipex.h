/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:55:15 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/17 19:20:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pip
{
	char	**argv;
	char	**path;
	char	*cmd_path;
	int		fd;
}			t_pip;

//	utils
t_pip		*pip_init(t_pip *p, char **argv, char **env);
char		**ft_split_w_slash(const char *s, char c);
int			ft_isascii(int c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		**get_paths(char **env);
char		*find_cmd_path(t_pip *p, char *cmd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_putstr(char *str);

//	temp
void		print_path(t_pip *p);

#endif