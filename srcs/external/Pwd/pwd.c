/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:49:22 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 13:49:32 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int argc, char *argv[], char *envp[])
{
	char	*pwd;
	
	if (!(pwd = get_env(envp, "PWD")))
	{
		ft_write_n(2, "pwd allocation error");
		g_last_ret = 2;
		return (1);
	}
	g_last_ret = 0;
	ft_write_n(1, pwd);
	return (0);
}
