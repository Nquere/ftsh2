/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:13 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 16:00:03 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_my_end(char const *s)
{
	int		i;

	i = ft_strlen(s);
	while ((s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t') && i > 0)
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	start = 0;
	end = 0;
	i = 0;
	if (s)
	{
		start = ft_my_start(s);
		end = ft_my_end(s);
		start = (start > end) ? 0 : start;
		new = (char *)malloc((sizeof(char) * (end - start)) + 1);
		if (new == NULL)
			return (NULL);
		while (i < (end - start))
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
