/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:33:52 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/20 18:22:39 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parser_bonus(t_pip *p, int argc, char **argv, char **env)
{
	int	fd;
	int	i;

	pip_init_to_null(p);
	if (argc < 5)
		return (free_print_exit(p, "Error : wrong number of arguments\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), free_print_exit(p, "Error : input file not found\n"));
	fd = open(argv[argc - 1], O_RDWR, 0644);
	if (fd < 0)
		return (close(fd), free_print_exit(p,
				"Error : output file not found\n"));
	p->paths = get_paths(env);
	i = 1;
	while (++i < argc - 1)
	{
		p->cmd1_split = ft_split(argv[i], ' ');
		if (!find_cmd_path(p, p->cmd1_split[0]))
			return (free_print_exit(p, "Error : command not found\n"));
		free(p->cmd_path);
		free_tab(p->cmd1_split);
	}
	free_tab(p->paths);
}
