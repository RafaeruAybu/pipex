/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:35:00 by igearhea          #+#    #+#             */
/*   Updated: 2021/06/26 19:35:01 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(t_all *all, char *cmd_name, int cmd_num)
{
	char	**for_search_str;
	char	*full_pth;

	for_search_str = all->paths;
	while (*for_search_str)
	{
		if (full_pth)
			free(full_pth);
		full_pth = get_path_to_cmd(*for_search_str, cmd_name);
		if (!access(full_pth, R_OK))
		{
			if (cmd_num == 1)
				all->full_path_to_cmd1 = ft_strjoin("", full_pth);
			else
				all->full_path_to_cmd2 = ft_strjoin("", full_pth);
			free(full_pth);
			full_pth = NULL;
			return (0);
		}
		for_search_str++;
	}
	save_exit(1, "ERROR!\nCommand not found!\n");
	return (1);
}

int	check_all_cmds(t_all *all)
{
	check_cmd(all, all->args1[0], 1);
	check_cmd(all, all->args2[0], 2);
	return (0);
}

int	check_files(t_all *all)
{
	all->fd_infile = open(all->argv[1], O_RDONLY);
	if (all->fd_infile < 0)
		save_exit(-1, "ERROR!\nCant open input file.\n");
	if (!access(all->argv[4], F_OK))
		if (unlink(all->argv[4]))
			save_exit(-1, "ERROR!\nCant remove output file.\n");
	all->fd_outfile = open(all->argv[4], O_WRONLY | O_CREAT, 0644);
	if (all->fd_outfile < 0)
		save_exit(-1, "Cant open output file.\n");
	return (0);
}

//todo не забыть проверять пустой ENV
void	parse_path(t_all *all)
{
	char	**ptr;

	ptr = all->env;
	while (*ptr)
	{
		if (!ft_strncmp(*ptr, "PATH=", 5))
			break ;
		ptr++;
	}
	(*ptr) = (*ptr) + 5;
	all->paths = ft_split(*ptr, ':');
}

int	validate_args(int argc, char **argv, char **env, t_all *all)
{
	if (argc < 5)
		save_exit(1, "ERROR!\nNot enough arguments!\n"
			 "Syntax is: ./pipex infile \"cmd1 [args]\" \"cmd2 [args]\" outfile\n");
	else if (argc > 5)
		save_exit(1, "ERROR!\nToo much arguments!\n"
			 "Syntax is: ./pipex infile \"cmd1 [args]\" \"cmd2 [args]\" outfile\n");
	if (!env)
		save_exit(1, "ERROR!\nEnvironment not found!\n");
	if (!argv)
		save_exit(1, "ERROR!\nArguments not found!\n");
	check_files(all);
	parse_cmd_str(all);
	parse_path(all);
	check_all_cmds(all);
	return (0);
}
