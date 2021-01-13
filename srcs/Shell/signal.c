/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:29 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 14:50:49 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle(int signum)
{
	ft_write_n(1, "");
	ft_write(1, "$> ");
}

void		sig_int(void)
{
	signal(SIGINT, handle);
	signal(SIGTSTP, handle);
}
