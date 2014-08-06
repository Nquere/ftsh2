/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:12:43 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 16:11:50 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

int		ft_check(char **env, char *arg)
{
	int		i;
	char	*pwd;
	char	*tmp;

	tmp = NULL;
	pwd = NULL;
	i = 0;
	while ((env)[i] && ft_strcmp2((env)[i], "PWD=") != 0)
		i++;
	if ((env)[i])
	{
		pwd = ft_strchr((env)[i], '/');
		tmp = ft_strjoin(ft_strjoin(pwd, "/"), arg);
		if (access(tmp, R_OK) == -1 && access(arg, R_OK))
		{
			ft_print_er("cd: permission denied: ", arg);
			return (1);
		}
	}
	if (opendir(tmp) == NULL && opendir(arg) == NULL)
	{
		ft_print_er("cd: not a directory: ", arg);
		return (1);
	}
	return (0);
}

void	ft_dash(char ***env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while ((*env)[j] && ft_strcmp2((*env)[j], "OLDPWD=") != 0)
		j++;
	while ((*env)[i] && ft_strcmp2((*env)[i], "PWD=") != 0)
		i++;
	if ((*env)[j] && (*env)[i])
	{
		tmp = getcwd(NULL, 0);
		chdir(&(*env)[j][7]);
		(*env)[j] = ft_strjoin("OLDPWD=", tmp);
		(*env)[i] = ft_strjoin("PWD=", getcwd(NULL, 0));
	}
	else
		ft_putendl_fd(": no such file or directory", 2);
}

void	ft_home(char ***env, char *home)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*env)[j] && ft_strcmp2((*env)[j], "OLDPWD=") != 0)
		j++;
	while ((*env)[i] && ft_strcmp2((*env)[i], "PWD=") != 0)
		i++;
	(*env)[j] = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
	chdir(home);
	(*env)[i] = ft_strjoin("PWD=", home);
}

void	ft_modif(char ***env, char **arg, int i)
{
	if (arg[2])
		(*env)[i] = ft_strjoin(arg[1], ft_strjoin("=", arg[2]));
	else
		(*env)[i] = ft_strjoin(arg[1], "=");
}
