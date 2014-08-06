/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:11 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:58:39 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	if (s && f)
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(s));
		while (s[i])
		{
			new[i] = (*f)(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
