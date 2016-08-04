/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:08:15 by jbester           #+#    #+#             */
/*   Updated: 2016/08/04 13:51:34 by jbester          ###   ########.fr       */
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
char	**ft_unsetenv(char **env, char *line);
char	**ft_update_env(char **env, char *name, char *value);
void	get_pwd(void);
int		change_dir(char *line, char **env);
int		check_dir(char *dir);
char	**ft_set_oldpwd(char **env);
char	**ft_set_pwd(char **env);
char	*ft_cd_back(char **env);

#endif
