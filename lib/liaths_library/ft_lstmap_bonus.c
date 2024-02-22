/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:55 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:15 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstmap
Prototype 			t_list *ft_lstmap(t_list *lst, void *(*f)(void *), 
					void (*del)(void *));
Turn in files 		-
Parameters 			lst: The address of a pointer to a node.
					f: The address of the function used to iterate on the list.
					del: The address of the function used to delete the content
					of a node if needed.
Return value 		The new list.
					NULL if the allocation fails.
External functs. 	malloc, free
Description 		Iterates the list ’lst’ and applies the function
					’f’ on the content of each node. Creates a new
					list resulting of the successive applications of
					the function ’f’. The ’del’ function is used to
					delete the content of a node if needed.
*/

#include "liaths_library.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;
	t_list	*new_lst;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = (f(lst->content));
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
