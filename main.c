/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:07:40 by jbester           #+#    #+#             */
/*   Updated: 2016/08/04 14:03:56 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*Working on cd flags!*/

int	ft_check(char *line, char **nenv)
{
	ft_skip(&line);
	if (*line == '\0')
		return (1);
	if (ft_strncmp(line, "exit", 3) == 0)
		exit(0);
	if (ft_strncmp(line, "env", 3) == 0)
	{
		ft_display_env(nenv);
		return (1);
	}
	if (ft_strncmp(line, "pwd", 3) == 0)
	{
		get_pwd();
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	**nenv;

	(void)argc;
	(void)argv;
	line = 0;
	nenv = ft_cpy_env(env, 0);
	ft_putstr("Shell> ");
	while ((ft_get_next_line(0, &line)) > 0)
	{
		if ((ft_strncmp(line, "setenv", 6)) == 0)
			nenv = ft_setenv(nenv, line);
		else if ((ft_strncmp(line, "unsetenv", 8)) == 0)
			nenv = ft_unsetenv(nenv, line);
		else if (ft_strncmp(line, "cd", 2) == 0)
			change_dir(line, nenv);
		else if (ft_check(line, nenv) == 0)
		{
			ft_putstr("21sh does not recognise the command: ");
			ft_putendl(line);
		}
		ft_putstr("Shell> ");
	}
	return (0);
}
