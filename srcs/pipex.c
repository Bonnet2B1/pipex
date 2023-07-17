/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:51:40 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/17 16:47:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pip	*p;
	p = pip_init(p);
}

// int main(void)
// {
// 	pid_t	pid;

// 	if ((pid = fork()) == -1)
// 		{
// 			perror("fork");
// 			return 1;
// 		}
// 	else if (pid != 0)
// 		printf("Je suis le pere, et mon pid = %d. Le pid de mon fils = %d\n", getpid(), pid);
// 	else
// 		printf("Je suis le fils, et mon pid = %d\n", getpid());
// 	return 0;
// }