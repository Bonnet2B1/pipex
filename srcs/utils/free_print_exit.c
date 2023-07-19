/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_print_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:07:56 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/19 19:26:34 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	freeall(t_pip *p)
{
	if (p)
	{
		free_tab(p->cmd1_split);
		free_tab(p->cmd2_split);
		free_tab(p->paths);
		if (p->cmd_path)
			free(p->cmd_path);
		p->cmd_path = NULL;
		free(p);
	}
}

void	free_print_exit(t_pip *p, char *str)
{
	freeall(p);
	ft_putstr(str);
	exit(0);
}