/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:51:40 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/20 18:28:02 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_execmd(t_pip *p, char **cmd_split)
{
	if (execve(find_cmd_path(p, cmd_split[0]), cmd_split, NULL) == -1)
		return (free_print_exit(p, "Error : execve\n"));
}

void	pipe_n_execmd1(t_pip *p, int pid1)
{
	if (pid1 < 0)
		return (free_print_exit(p, "Error : fork failed\n"));
	if (pid1 != 0)
	{
		dup2(open(p->stdin, O_RDONLY, 0644), STDIN_FILENO);
		dup2(p->pipe_fd[1], STDOUT_FILENO);
		close(p->pipe_fd[0]);
		close(p->pipe_fd[1]);
		ft_execmd(p, p->cmd1_split);
	}
	waitpid(pid1, NULL, 0);
}

void	pipe_n_execmd2(t_pip *p, int pid2)
{
	if (pid2 < 0)
		return (free_print_exit(p, "Error : fork failed\n"));
	if (pid2 != 0)
	{
		dup2(p->pipe_fd[0], STDIN_FILENO);
		dup2(open(p->stdout, O_RDWR | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
		close(p->pipe_fd[0]);
		close(p->pipe_fd[1]);
		ft_execmd(p, p->cmd2_split);
	}
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pip	*p;

	(void)argc;
	p = malloc(sizeof(t_pip));
	if (!p)
		return (free_print_exit(p, "Error : malloc failed\n"), 0);
	parser(p, argc, argv, env);
	p = pip_init(p, argv, env);
	if (pipe(p->pipe_fd) == -1)
		return (free_print_exit(p, "Error : pipe failed\n"), 0);
	pipe_n_execmd1(p, fork());
	pipe_n_execmd2(p, fork());
	close(p->pipe_fd[1]);
	close(p->pipe_fd[0]);
	free_print_exit(p, NULL);
}
