#include "pipex.h"

int	parse_cmd_str(t_all *all)
{
	all->args1 = ft_split(all->argv[2], ' ');
	all->args2 = ft_split(all->argv[3], ' ');
	return (0);
}
