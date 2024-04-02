/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:02 by livliege          #+#    #+#             */
/*   Updated: 2024/02/27 12:06:26 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstclear
Prototype 			void ft_lstclear(t_list **lst, void (*del)(void*));
Turn in files 		-
Parameters 			lst: 	The address of a pointer to a node.
					del: 	The address of the function used to delete
							the content of the node.
Return value 		None
External functs. 	free
Description 		Deletes and frees the given node and every 
					successor of that node, using the function ’del’
					and free(3).
					Finally, the pointer to the list must be set to NULL.
*/

#include "../../../inc/lib_liath.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
