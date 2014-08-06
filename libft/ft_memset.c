/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:08 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:57:28 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((char *)str)[i] = value;
		i++;
	}
	return (str);
}
