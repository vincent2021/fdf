/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:15:05 by vimucchi          #+#    #+#             */
/*   Updated: 2018/04/30 21:57:17 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*mew;

	if (!lst)
		return (NULL);
	mew = f(lst);
	new = mew;
	while (lst->next)
	{
		lst = lst->next;
		if (!(mew->next = f(lst)))
		{
			free(mew->next);
			return (NULL);
		}
		mew = mew->next;
	}
	return (new);
}
