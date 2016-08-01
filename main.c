/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:07:40 by jbester           #+#    #+#             */
/*   Updated: 2016/07/28 15:28:02 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	ft_check(char *line, char **nenv)
{
	ft_skip(&line);
	if (*line == '\0')
		return (1);
	if (ft_strncmp(line, "exit", 4) == 0)
		exit (0);
	if (ft_strncmp(line, "env", 3) == 0)
	{
		ft_display_env(nenv);
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
		if (ft_strncmp(line, "setenv", 6) == 0)
			nenv = ft_setenv(nenv, line);
		else if (ft_strncmp(line, "unsetenv", 6) == 0)
			ft_unsetenv(&nenv, line);
		else if (ft_check(line, nenv) == 0)
		{
			ft_putstr("21sh does not recognise the command: ");
			ft_putendl(line);
		}
		ft_putstr("Shell> ");
	}
	return (0);
}
