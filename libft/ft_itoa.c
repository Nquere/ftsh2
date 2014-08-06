/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:06 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 15:54:54 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_ifneg(char *str, int *n)
{
	*n = -*n;
	str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	size = ft_lenstr(n);
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (str == NULL)
		return (NULL);
	ft_strclr(str);
	str[size] = '\0';
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
		str = ft_ifneg(str, &n);
	i = size - 1;
	while (i >= 0)
	{
		if (str[i] != '-')
			str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
