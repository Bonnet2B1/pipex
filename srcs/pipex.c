/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:51:40 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/18 18:57:41 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_execmd(t_pip *p, char **cmd_split)
{
	if (execve(find_cmd_path(p, cmd_split[0]), cmd_split, NULL) == -1)
		return (ft_putstr("Error: execve\n"));
}

int	main(int argc, char **argv, char **env)
{
	t_pip	*p;
	int		pipe_fd[2];
	int		pid1;
	int		pid2;

	(void)argc;
	
	p = malloc(sizeof(t_pip));
	p = pip_init(p, argv, env);
	
	if (pipe(pipe_fd) == -1)
		return (ft_putstr("Error: pipe\n"), 0);
	
	pid1 = fork();
	if (pid1 < 0)
		return (ft_putstr("Error: fork\n"), 0);

	if (pid1 == 0)
	{
		// chaild process (cmd1)
		dup2(open(p->stdin, O_RDONLY, 0644), STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		ft_execmd(p, p->cmd1_split);
	}
	
	pid2 = fork();
	if (pid2 < 0)
		return (ft_putstr("Error: fork\n"), 0);

	if (pid2 == 0)
	{
		// chaild process (cmd2)
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(open(p->stdout, O_RDWR | O_CREAT | O_TRUNC, 0644) , STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		ft_execmd(p, p->cmd2_split);
	}
	
	close(pipe_fd[1]);
	close(pipe_fd[0]);

	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);  

	// system(find_cmd_path(p, "ls"));
	// print_path(p);
	// printf("fd = %d\n", open("/Users/eli/Documents/GitHub/Cursus/pipex/stdin.txt", O_RDONLY));
}

// int main(void)
// {
// 	pid_t	pid;

// 	if ((pid = fork()) == -1)
// 		{
// 			perror("fork");
// 			return (1);
// 		}
// 	else if (pid != 0)
// 		printf("Je suis le pere, et mon pid = %d. Le pid de mon fils = %d\n",
//				getpid(), pid);
// 	else
// 		printf("Je suis le fils, et mon pid = %d\n", getpid());
// 	return (0);
// }