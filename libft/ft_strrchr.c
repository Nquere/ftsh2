/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:12 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:59:32 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int		i;

	i = ft_strlen(src);
	while (i != -1)
	{
		if (src[i] == (char)c)
			return (&((char *)src)[i]);
		i--;
	}
	return (NULL);
}
