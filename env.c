/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:28:17 by jbester           #+#    #+#             */
/*   Updated: 2016/07/28 15:19:28 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_env_size(char **env)
{
	int	l;

	l = 0;
	while (env[l])
		l++;
	return (l);
}

char	**ft_cpy_env(char **env, int extra)
{
	int		size;
	int		i;
	int		count;
	char	**nenv;

	size = ft_env_size(env);
	i = 0;
	count = 0;
	nenv = (char **)malloc(sizeof(char *) * size + extra);
	while (env[count] != NULL)
	{
		nenv[i] = ft_strdup(env[count]);
		count++;
		i++;
	}
	return (nenv);
}

void	ft_display_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
}

char	**ft_setenv(char **env, char *line)
{
	char	**new;
	int		i;
	char	*temp;
	char	**info;
	char	*nline;

	i = 0;
	ft_putendl("entered");
	info = ft_strsplit(line, ' ');
	nline = ft_strjoin(info[1], "=");
	nline = ft_strjoin(nline, info[2]);
	ft_putendl(nline);
	new = ft_cpy_env(env, 1);
	free(env);
	temp = NULL;
	while (ft_strncmp(new[i], "_=", 2) != 0)
		i++;
	if (ft_strncmp(new[i], "_=", 2) == 0)
	{
		temp = ft_strcpy(temp, env[i]);
		free(new[i]);
		new[i] = ft_strdup(nline);
		new[++i] = ft_strdup(temp);
	}
	return (new);
}
