/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:04:24 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 15:40:27 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		prompt(char **line)
{
	int len;
	int flag;

	ft_write(1, "$> ");
	if ((flag = get_next_line(0, line)) == 0)
	{
		ft_write_n(1, "^D");
		return (1);
	}
	return (0);
}
