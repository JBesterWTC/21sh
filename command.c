/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:20:52 by jbester           #+#    #+#             */
/*   Updated: 2016/08/04 13:59:41 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	get_pwd(void)
{
	char	buf[4096];

	getcwd(buf, 4096);
	ft_putendl(buf);
}

int		change_dir(char *line, char **env)
{
	char	**info;

	info = ft_strsplit(line, ' ');
	env = ft_set_oldpwd(env);
	ft_display_env(env);
	if (info[1][0] == '-' || (!info[1]))
			info[1] = ft_cd_back(env);
	if (check_dir(info[1]) == 0)
	{
		chdir(info[1]);
		env = ft_set_pwd(env);
		return (0);
	}
	return (1);
}

int		check_dir(char *dir)
{
	if (access(dir, X_OK) == 0)
		return (0);
	else
	{
		ft_putstr("Invalid file or directory: ");
		ft_putendl(dir);
	}
	return (1);
}

char	*ft_cd_back(char **env)
{
	int		i;
	char	**dir;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			dir = ft_strsplit(env[i], '=');
			return (dir[1]);
		}
		i++;
	}
	return (0);
}
