/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:12:19 by seolim            #+#    #+#             */
/*   Updated: 2021/01/13 14:12:34 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "lib.h"

char	**key_value_parse(char *env_string);
char	**init_envp(char *old_envp[]);
char	*get_env(char *envp[], char *key);
int		set_env(char *envp[], char *env_string);
int		add_env(char ***envp, char *env_string);
int		delete_env(char ***envp, char *key);

#endif
