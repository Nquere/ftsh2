/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:12:43 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 16:11:37 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

void	ft_cd(char ***env, char **arg, char *home)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (arg[1] == NULL)
		ft_home(env, home);
	else if (ft_strcmp(arg[1], "~") == 0)
		ft_home(env, home);
	else if (ft_strcmp(arg[1], "-") == 0)
		ft_dash(env);
	else if (ft_check((*env), arg[1]) == 0)
	{
		while ((*env)[i] && ft_strcmp2((*env)[i], "OLDPWD=") != 0)
			i++;
		while ((*env)[j] && ft_strcmp2((*env)[j], "PWD=") != 0)
			j++;
		(*env)[i] = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
		if (arg[1][0] != '/')
			chdir(ft_strjoin(&(*env)[j][4], ft_strjoin("/", arg[1])));
		else
			chdir(arg[1]);
		(*env)[j] = ft_strjoin("PWD=", getcwd(NULL, 0));
	}
}

void	ft_exit(char ***env, char **arg, char *home)
{
	(void)env;
	(void)arg;
	(void)home;
	_exit(1);
}

void	ft_env(char ***env, char **arg, char *home)
{
	int		i;

	(void)home;
	(void)arg;
	i = 0;
	while ((*env)[i])
	{
		ft_putendl((*env)[i]);
		i++;
	}
}

void	ft_setenv(char ***env, char **arg, char *home)
{
	int		i;
	int		j;

	(void)home;
	j = 0;
	while (arg[j])
		j++;
	i = 0;
	if (ft_strchr(arg[1], '=') == NULL)
	{
		while ((*env)[i] && ft_strcmp2((*env)[i], arg[1]) != 0)
			i++;
		if ((*env)[i] == NULL)
		{
			*env = ft_realloc(env);
			ft_modif(env, arg, i);
		}
		else if (arg[3] == NULL || (arg[3] && j > 1
					&& ft_strcmp(arg[3], "0") != 0))
			ft_modif(env, arg, i);
	}
	else
		ft_putendl_fd("setenv: Syntax Error.", 2);
}

void	ft_unsetenv(char ***env, char **arg, char *home)
{
	int		i;

	(void)home;
	i = 0;
	while (ft_strcmp2((*env)[i], arg[1]) != 0)
		i++;
	while ((*env)[i + 1])
	{
		(*env)[i] = (*env)[i + 1];
		i++;
	}
	(*env)[i] = NULL;
}
