/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:11 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:58:28 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;
	int		j;

	i = 0;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		new = (char *)malloc((sizeof(char) * (len1 + len2)) + 1);
		if (new == NULL)
			return (NULL);
		j = 0;
		while (j < len1)
			new[i++] = s1[j++];
		j = 0;
		while (j < len2)
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
