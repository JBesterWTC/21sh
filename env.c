/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:28:17 by jbester           #+#    #+#             */
/*   Updated: 2016/08/04 13:38:47 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_env_size(char **env)
{
	int	l;

	l = 0;
	while (env[l] != NULL)
		l++;
	return (l);
}

char	**ft_cpy_env(char **env, int extra)
{
	int		size;
	int		i;
	int		count;
	char	**nenv;

	size = ft_env_size(env) + extra;
	i = 0;
	count = 0;
	nenv = (char **)malloc(sizeof(char *) * size + 1);
	while (env[count] != NULL)
	{
		nenv[i] = ft_strdup(env[count]);
		count++;
		i++;
	}
	nenv[i] = NULL;
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
	info = ft_strsplit(line, ' ');
	while (info[i] != NULL)
		i++;
	if (i != 3)
	{
		ft_putendl("Not enough commands for setenv.\
					Try: setenv [NAME] [value].");
		return (0);
	}
	nline = ft_strjoin(info[1], "=");
	nline = ft_strjoin(nline, info[2]);
	i = 0;
	temp = NULL;
	new = ft_cpy_env(env, 1);
	free(env);
	while (ft_strncmp(new[i], "_=", 2) != 0)
	{
		if (ft_strncmp(new[i], info[1], ft_strlen(info[1])) == 0)
		{
			env = ft_update_env(new, info[1], info[2]);
			return (env);
		}
		i++;
	}
	if (ft_strncmp(new[i], "_=", 2) == 0)
	{
		temp = ft_strdup(env[i]);
		free(new[i]);
		new[i] = ft_strdup(nline);
		new[++i] = ft_strdup(temp);
		free(temp);
	}
	new[++i] = NULL;
	return (new);
}

char	**ft_unsetenv(char **env, char *line)
{
	int		i;
	char	*temp;
	char	**new;
	char	**nenv;

	i = 0;
	new = ft_strsplit(line, ' ');
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], new[1], ft_strlen(new[1])) == 0)
		{
			ft_strdel(&env[i]);
			i++;
			temp = ft_strdup(env[i]);
			env[i - 1] = ft_strdup(temp);
			free(temp);
			free(env[i]);
			env[i] = NULL;
			nenv = ft_cpy_env(env, 0);
			free(env);
		}
		i++;
	}
	return (env);
}
