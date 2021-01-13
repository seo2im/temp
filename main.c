/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:08:14 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 14:11:33 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	arr_init(char str[255])
{
	int	i;

	i = -1;
	while (++i < 255)
		str[i] = 0;
}

int			global_init(void)
{
	g_last_ret = 0;
	g_pipe_cmd = NULL;
	g_envp = NULL;
	g_input = NULL;
	g_cmd = NULL;
	g_argv = NULL;
	g_argv_p = NULL;
}

int			shell(char **input)
{
	int		start;
	int		i;

	i = -1;
	start = 0;
	while (input[++i])
	{
		if (!strcmp(input[i], ";"))
		{
			g_cmd = ft_strsndup(input + start, i);
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
	char	str[255];
	int		i;

	arr_init(str);
	sig_int();
	global_init();
	g_envp = init_envp(envp);
	while (TRUE)
	{
		prompt(str);
		if (!pre_parsing(str, &g_input))
			continue;
		i = -1;
		shell(g_input);
		ft_double_free(g_input);
	}
	ft_double_free(g_envp);
}
