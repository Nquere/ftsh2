/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:13 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:59:56 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (s)
	{
		new = (char *)malloc((sizeof(char) * len) + 1);
		if (new == NULL)
			return (NULL);
		while (i < len)
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[len] = '\0';
		return (new);
	}
	return (NULL);
}
