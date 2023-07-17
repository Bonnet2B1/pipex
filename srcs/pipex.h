/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:55:15 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/17 18:01:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pip
{
	char	**argv;
	char	**path;
	char	*cmd;
	int		fd;
}			t_pip;

//	utils
t_pip		*pip_init(t_pip *p, char **argv, char **env);
char		**ft_split(const char *s, char c);
int			ft_isascii(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**get_path(char **env);

//	temp
void		print_path(t_pip *p);

#endif