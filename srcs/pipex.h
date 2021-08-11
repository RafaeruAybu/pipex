/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:34:47 by igearhea          #+#    #+#             */
/*   Updated: 2021/06/26 19:34:48 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# include "Libft/libft.h"

typedef struct s_all
{
	char		**paths;
	char		*full_path_to_cmd1;
	char		*full_path_to_cmd2;
	char		**args1;
	char		**args2;
	int			fd_infile;
	int			fd_outfile;
	int			argc;
	char		**argv;
	char		**env;
}				t_all;

int		all_build(t_all *all, int argc, char **argv, char **env);
int		all_destroy(t_all *all);
void	save_exit(int num, char *str);
int		check_all_cmds(t_all *all);
int		check_files(t_all *all);
int		validate_args(int argc, char **argv, char **env, t_all *all);
int		parse_cmd_str(t_all *all);
void	clear_2d_str(char **str);
void	parse_path(t_all *all);
int		check_cmd(t_all *all, char *cmd_name, int cmd_num);
char	*get_path_to_cmd(char *pth, char *name_of_cmd);

#endif
