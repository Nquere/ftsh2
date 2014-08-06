/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 16:13:23 by nquere            #+#    #+#             */
/*   Updated: 2014/05/18 01:47:40 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell2.h"

static t_ptr	g_ptr[6] =
{
	{"cd", ft_cd},
	{"exit", ft_exit},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{0, 0}
};

static int	ft_builtin(char ***env, char **arg, char *home)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(g_ptr[i].s, arg[0]) == 0)
		{
			g_ptr[i].fct(env, arg, home);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_fork(char **arg, char **env, char **path)
{
	pid_t	v_pid;
	int		i;

	i = 0;
	v_pid = fork();
	wait(&i);
	if (v_pid == 0)
	{
		i = 0;
		if (path)
		{
			while (path[i])
			{
				execve(ft_strjoin(path[i], arg[0]), arg, env);
				i++;
			}
		}
		execve(arg[0], arg, env);
		ft_print_er("ft_minishell2: command not found: ", arg[0]);
		exit(0);
	}
}

static void	ft_minishell2(char **env, char **path)
{
	char	**arg;
	char	*home;

	arg = NULL;
	home = NULL;
	while (42)
	{
		ft_putstr("ft_minishell2# ");
		if ((arg = ft_get_arg()) == NULL || arg[0] == '\0')
			continue ;
		home = ft_get_home(env, home);
		path = ft_get_path(env, path);
		if (arg)
		{
			if (ft_builtin(&env, arg, home) == 0)
				ft_fork(arg, env, path);
		}
	}
}

void		ft_print_er(char *str, char *arg)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(arg, 2);
}

int			main(int ac, char **av, char **envp)
{
	char	**env;
	char	**path;

	(void)ac;
	(void)av;
	path = NULL;
	env = NULL;
	if (envp[0] != NULL)
	{
		env = ft_strdup2d(env, envp);
		ft_minishell2(env, path);
	}
	else
	{
		ft_putstr_fd("Please, don't be a troll", 2);
		ft_putendl_fd(", execute my shell with valid env", 2);
	}
	return (0);
}
