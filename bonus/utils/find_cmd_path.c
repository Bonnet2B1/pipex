/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:24:04 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/21 18:56:16 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*find_cmd_path(t_pip *p, char *cmd)
{
	int	i;

	i = -1;
	while (p->paths[++i])
	{
		p->cmd_path = ft_strjoin(p->paths[i], cmd);
		if (access(p->cmd_path, F_OK | X_OK) == 0)
			return (p->cmd_path);
		else if (p->cmd_path)
		{
			free(p->cmd_path);
			p->cmd_path = NULL;
		}
	}
	return (NULL);
}
