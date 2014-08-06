/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:10 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 16:01:56 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	if (s1)
	{
		cpy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
		while (s1[i])
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return ("\0");
}
