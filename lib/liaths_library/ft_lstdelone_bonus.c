/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:13 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:06 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstdelone
Prototype 			void ft_lstdelone(t_list *lst, void (*del)(void*));
Turn in files 		-
Parameters 			lst: The node to free.
					del: The address of the function used to delete the content.
Return value 		None
External functs. 	free
Description 		Takes as a parameter a node and frees the memory of
					the node’s content using the function ’del’ given
					as a parameter and free the node. The memory of
					’next’ must not be freed.
*/

#include "liaths_library.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// ft_lstdelone(head, &free);	this is for testing purposes

/*In this function we are taking in, as a parameter, the address of a pointer 
 * on a link and freeing the memory content of the link with the function 'del'
 * that has been passed as a parameter as well in order to free the memory of 
 * the link. The memory of the element next should never be freed. In order to
 * terminate the link, the pointer on the current link should be put to NULL.*/

/*First we check to make sure that the parameters that were passed into our
 * function are not NULL. If they are not we then run our parameter passed
 * function del by giving it's parameters our link alst's content and
 * content_size. Once the function has deleted alst's content we the free
 * the memory that was allocated to alst and then set it to NULL. Thus
 * deleting on link in our list.*/