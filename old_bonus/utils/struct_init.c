/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:45:25 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/19 18:20:07 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pip	*pip_init(t_pip *p, int argc, char **argv, char **env)
{
	p->argv = argv;
	p->env = env;
	p->paths = get_paths(env);
	p->stdin = argv[1];
	p->cmd1 = argv[p->i + 2];
	p->cmd2 = argv[p->i + 3];
	p->stdout = argv[argc - 1];
	p->cmd1_split = ft_split(p->cmd1, ' ');
	p->cmd2_split = ft_split(p->cmd2, ' ');
	return (p);
}
