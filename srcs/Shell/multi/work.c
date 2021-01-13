/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:01:33 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 16:27:29 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	work3(char **argv_p)
{
	if (!ft_strcmp(argv_p[0], "echo"))
		echo(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "env"))
		env(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "pwd"))
		pwd(ft_strslen(argv_p), argv_p, g_envp);
	if (!ft_strcmp(argv_p[0], "cd"))
		cd(argv_p[1]);
	if (!ft_strcmp(argv_p[0], "export"))
		export(argv_p);
	if (!ft_strcmp(argv_p[0], "unset"))
		unset(argv_p);
	if (!ft_strcmp(argv_p[0], "exit"))
		ft_exit();
}

static int	work2(char **argv, int fd[2], int backup[2])
{
	int		i;

	if (!(g_argv_p = double_alloc(ft_strslen(argv))))
		return (FALSE);
	i = -1;
	while (argv[++i])
		g_argv_p[i] = argv_parsing(argv[i]);
	std_backup(fd, backup);
	if (!is_cmd(g_argv_p[0]))
	{
		ft_double_free(g_argv_p);
		return (FALSE);
	}
	work3(g_argv_p);
	ft_double_free(g_argv_p);
	return (TRUE);
}

int			work(char **cmd)
{
	int		fd[2];
	int		backup[2];

	fd[0] = 0;
	fd[1] = 1;
	if (!(g_argv = redirection(cmd, fd)))
		return (FALSE);
	if (!work2(g_argv, fd, backup))
	{
		ft_double_free(g_argv);
		return (FALSE);
	}
	ft_double_free(g_argv);
	std_reset(fd, backup);
	return (TRUE);
}
