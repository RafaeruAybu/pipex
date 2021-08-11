#include "pipex.h"

static void	exec_second_cmd(int fd1[2], t_all *all)
{
	int	id2;

	id2 = fork();
	if (id2 == 0)
	{
		close(fd1[1]);
		dup2(fd1[0], 0);
		dup2(all->fd_outfile, 1);
		execve(all->full_path_to_cmd2, all->args2, all->env);
		exit(3);
	}
	else
		wait(NULL);
}

static int	do_work(t_all *all)
{
	int	fd1[2];
	int	id1;

	if (pipe(fd1) == -1)
		save_exit(1, "ERROR!\nCant get pipe!\n");
	id1 = fork();
	if (id1 == 0)
	{
		close(fd1[0]);
		dup2(all->fd_infile, 0);
		dup2(fd1[1], 1);
		execve(all->full_path_to_cmd1, all->args1, all->env);
		exit(3);
	}
	else
	{
		exec_second_cmd(fd1, all);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_all	all;

	all_build(&all, argc, argv, env);
	do_work(&all);
	all_destroy(&all);
	return (0);
}
