/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:40:46 by jbester           #+#    #+#             */
/*   Updated: 2016/07/28 12:43:43 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_skip(char **s)
{
	while (*s && (**s == ' ' || **s == '\t' || **s == '\n'))
		(*s)++;
}

char	**ft_update_env(char **env, char *name, char *value)
{
	int		i;
	int		len;
	char	*new;
	char	*temp;

	i = 0;
	temp = 0;
	len = ft_strlen(name);
	new = ft_strjoin(name, "=");
	new = ft_strjoin(new, value);
	new = ft_strjoin(new, "\0");
	while (env[i])
	{
		if(ft_strncmp(env[i], name, len) == 0)
		{
			temp = ft_strdup(env[i]);
			free(env[i]);
			env[i] = ft_strdup(temp);
			return (env);
		}
		i++;
	}
	return (env);
}
