/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:07 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:56:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)src)[i]);
		i++;
	}
	return (NULL);
}
