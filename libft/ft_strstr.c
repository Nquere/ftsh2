/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:12 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:59:51 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *test)
{
	int		i;
	int		j;

	i = 0;
	if (test[i] == 0)
		return ((char *)src);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == test[j])
		{
			if (test[j + 1] == '\0')
				return (&((char *)src)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
