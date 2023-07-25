/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:45:25 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/25 16:21:34 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

t_pip	*pip_init_to_null(t_pip *p)
{
	p->paths = NULL;
	p->cmd_path = NULL;
	p->cmd1_split = NULL;
	p->cmd2_split = NULL;
	return (p);
}

t_pip	*pip_init(t_pip *p, int argc, char **argv, char **env)
{
	p->argv = argv;
	p->env = env;
	p->stdin = argv[1];
	p->cmd1 = argv[p->i + 2];
	p->cmd2 = argv[p->i + 3];
	p->stdout = argv[argc - 1];
	if (!p->paths)
		p->paths = get_paths(env);
	p->cmd1_split = ft_split(p->cmd1, ' ');
	p->cmd2_split = ft_split(p->cmd2, ' ');
	return (p);
}
