/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 15:37:53 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:58:14 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup2d(char **dest, char **src)
{
	int		i;

	i = 0;
	if (src)
	{
		while (src[i])
			i++;
		dest = (char **)malloc((sizeof(char *) * i) + 1);
		if (dest == NULL)
			ft_putendl_fd("Malloc env fail", 2);
		i = 0;
		while (src[i])
		{
			dest[i] = ft_strdup(src[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
