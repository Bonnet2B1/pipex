/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:45:25 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/17 18:36:54 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pip	*pip_init(t_pip *p, char **argv, char **env)
{
	p->argv = argv;
	p->path = get_paths(env);
	return (p);
}
