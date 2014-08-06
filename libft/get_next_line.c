/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:13 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 16:00:20 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(int const fd, char **buf)
{
	int		ret;

	ret = 0;
	*buf = (char *)malloc((sizeof(char) * BUFF_SIZE) + 1);
	if (*buf == NULL)
		return (-1);
	ret = read(fd, *buf, BUFF_SIZE);
	return (ret);
}

static char	*ft_strnjoin(char *s1, char const *s2, int n)
{
	char	*new;
	int		len1;
	int		i;
	int		j;

	i = 0;
	len1 = (s1 == NULL) ? 0 : ft_strlen(s1);
	new = (char *)malloc((sizeof(char) * (len1 + n)) + 1);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (j < len1)
		new[i++] = s1[j++];
	if (s1)
		ft_strdel(&s1);
	j = 0;
	while (j < n)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

static int	ft_buf(char **buf, int *i, char **line)
{
	while (*buf && (*buf)[(*i)])
	{
		if ((*buf)[(*i)] == '\n')
		{
			*line = ft_strnjoin(*line, *buf, (*i));
			(*i)++;
			*buf = &(*buf)[(*i)];
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	int			ret;
	int			i;

	*line = NULL;
	if (!buf)
		buf = ft_strnew(BUFF_SIZE + 1);
	while (1)
	{
		i = 0;
		if (ft_buf(&buf, &i, line) == 1)
			return (1);
		*line = ft_strnjoin(*line, buf, i);
		ret = ft_read(fd, &buf);
		if (ret < 1)
		{
			ft_strdel(&buf);
			return (ret);
		}
		buf[ret] = '\0';
	}
}
