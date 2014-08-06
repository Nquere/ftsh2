/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:10 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 14:13:10 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *src, const char *test)
{
	int		i;

	i = 0;
	while (src[i] || test[i])
	{
		if (src[i] != test[i])
			return (src[i] - test[i]);
		i++;
	}
	return (0);
}
