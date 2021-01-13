/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:08:14 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 16:19:13 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		global_init(void)
{
	g_last_ret = 0;
	g_pipe_cmd = NULL;
	g_envp = NULL;
	g_input = NULL;
	g_cmd = NULL;
	g_argv = NULL;
	g_argv_p = NULL;
}

void		shell(char **input)
{
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], ";"))
		{
			g_cmd = ft_strsndup(input + start, i - start);
			start = i + 1;
			piping(g_cmd);
			ft_double_free(g_cmd);
		}
	}
	if (start != i)
	{
		g_cmd = ft_strsndup(input + start, i);
		piping(g_cmd);
		ft_double_free(g_cmd);
	}
}

int			main(int argc, char *argv[], char *envp[])
{
	char	*line;

	sig_int();
	global_init();
	g_envp = init_envp(envp);
	while (TRUE)
	{
		if (prompt(&line))
			continue;
		if (!pre_parsing(line, &g_input))
			continue;
		shell(g_input);
		ft_double_free(g_input);
	}
	ft_double_free(g_envp);
}
