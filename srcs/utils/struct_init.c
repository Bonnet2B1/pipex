/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:45:25 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/20 18:19:04 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pip	*pip_init_to_null(t_pip *p)
{
	p->argv = NULL;
	p->env = NULL;
	p->paths = NULL;
	p->stdin = NULL;
	p->cmd1 = NULL;
	p->cmd2 = NULL;
	p->stdout = NULL;
	p->cmd_path = NULL;
	p->cmd1_split = NULL;
	p->cmd2_split = NULL;
	return (p);
}

t_pip	*pip_init(t_pip *p, char **argv, char **env)
{
	p->argv = argv;
	p->env = env;
	p->paths = get_paths(env);
	if (!p->paths)
		free_print_exit(p, "Error : PATH not found\n");
	p->stdin = argv[1];
	p->cmd1 = argv[2];
	p->cmd2 = argv[3];
	p->stdout = argv[4];
	p->cmd_path = NULL;
	p->cmd1_split = ft_split(p->cmd1, ' ');
	p->cmd2_split = ft_split(p->cmd2, ' ');
	return (p);
}
