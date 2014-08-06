/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 14:13:07 by nquere            #+#    #+#             */
/*   Updated: 2014/05/17 14:13:07 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && del && alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		alst = NULL;
	}
}
