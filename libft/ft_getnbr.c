/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:05 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 14:13:05 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(const char *str)
{
	int		i;
	int		n;
	int		k;

	i = 0;
	n = 0;
	k = 0;
	if ((str[i] < '0' || str[i] > '9') && (str[i] < 9 || str[i] > 13)
		&& str[i] != ' ' && str[i] != '+' && str[i] != '-')
		return (n);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i])
			k++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (str[i] - 48) + n * 10;
		i++;
	}
	return (n = (k % 2 != 0) ? n * (-1) : n);
}
