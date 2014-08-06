/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 16:11:22 by nquere            #+#    #+#             */
/*   Updated: 2014/05/18 02:03:55 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL2_H
# define MINISHELL2_H

# include "libft/includes/libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_ptr
{
	char			*s;
	void			(*fct)(char ***, char **, char *);
}					t_ptr;

void				ft_cd(char ***env, char **arg, char *home);
void				ft_exit(char ***env, char **arg, char *home);
void				ft_env(char ***env, char **arg, char *home);
void				ft_setenv(char ***env, char **arg, char *home);
void				ft_unsetenv(char ***env, char **arg, char *home);
char				**ft_get_arg(void);
char				**ft_get_path(char **env, char **path);
char				*ft_get_home(char **env, char *home);
void				ft_home(char ***env, char *home);
int					ft_strcmp2(const char *s1, const char *s2);
void				ft_cdarg(char ***env, char *arg);
int					ft_check(char **env, char *arg);
char				**ft_realloc(char ***env);
void				ft_dash(char ***env);
void				ft_print_er(char *str, char *arg);
void				ft_modif(char ***env, char **arg, int i);

#endif
