/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:17:21 by jbester           #+#    #+#             */
/*   Updated: 2016/08/04 12:27:59 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	**ft_set_oldpwd(char **env)
{
	char	res[4096];

	getcwd(res, 4096);
	env = ft_update_env(env, "OLDPWD", (char *)res);
	return (env);
}

char	**ft_set_pwd(char **env)
{
	char	res[4096];

	getcwd(res, 4096);
	env = ft_update_env(env, "PWD", (char *)res);
	return (env);
}
