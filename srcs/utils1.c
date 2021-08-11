#include "pipex.h"

int	all_build(t_all *all, int argc, char **argv, char **env)
{
	all->argc = argc;
	all->argv = argv;
	all->env = env;
	validate_args(argc, argv, env, all);
	return (0);
}

void	clear_2d_str(char **str)
{
	char	**saved_ptr;

	saved_ptr = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(saved_ptr);
}

int	all_destroy(t_all *all)
{
	if (close(all->fd_outfile))
		save_exit(-1, "ERROR!\nCant close file!\n");
	if (close(all->fd_infile))
		save_exit(-1, "ERROR!\nCant close file!\n");
	clear_2d_str(all->args1);
	clear_2d_str(all->args2);
	clear_2d_str(all->paths);
	return (0);
}

void	save_exit(int exit_num, char *str)
{
	perror(str);
	exit(exit_num);
}

char	*get_path_to_cmd(char *pth, char *name_of_cmd)
{
	char	*full_pth;
	char	*tmp;

	tmp = ft_strjoin(pth, "/");
	full_pth = ft_strjoin(tmp, name_of_cmd);
	free(tmp);
	return (full_pth);
}
