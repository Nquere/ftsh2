/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:12:44 by nquere            #+#    #+#             */
/*   Updated: 2014/05/18 01:46:49 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

char	**ft_get_arg(void)
{
	char	*line;
	char	**arg;

	arg = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line)
			arg = ft_strsplit(line, ' ');
		return (arg);
	}
	_exit(1);
}

char	*ft_get_home(char **env, char *home)
{
	int		i;

	i = 0;
	while ((env)[i] && ft_strncmp(env[i], "HOME=", 5) != 0)
		i++;
	if ((env)[i])
	{
		if (ft_strchr((env)[i], '/'))
			home = ft_strchr((env)[i], '/');
	}
	return (home);
}

char	**ft_get_path(char **env, char **path)
{
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i])
	{
		path = ft_strsplit(env[i], ':');
		path[0] = ft_strchr(path[0], '/');
		i = 0;
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			i++;
		}
	}
	return (path);
}

char	**ft_realloc(char ***env)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while ((*env)[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*env)[i])
	{
		tmp[i] = ft_strdup((*env)[i]);
		i++;
	}
	tmp[i + 1] = NULL;
	i = 0;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
	return (tmp);
}

int		ft_strcmp2(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
