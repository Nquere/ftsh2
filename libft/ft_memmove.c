/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:08 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:57:23 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			tmp[n + 1];

	i = 0;
	while (i < n)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = tmp[i];
		i++;
	}
	return (dest);
}
