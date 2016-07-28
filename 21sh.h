/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:08:15 by jbester           #+#    #+#             */
/*   Updated: 2016/07/28 15:11:48 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINI_H__
# define __MINI_H__
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"

int		ft_env_size(char **env);
char	**ft_cpy_env(char **env, int extra);
void	ft_display_env(char **env);
void	ft_skip(char **s);
char	**ft_setenv(char **env, char *line);

#endif
