/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:21 by livliege          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:09 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 		ft_lstiter
Prototype 			void ft_lstiter(t_list *lst, void (*f)(void *));
Turn in files 		-
Parameters 			lst: The address of a pointer to a node.
					f: The address of the function used to iterate on the list.
Return value 		None
External functs. 	None
Description 		Iterates the list ’lst’ and applies the function
					’f’ on the content of each node.
*/

#include "liaths_library.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* This function will be taking the function f, passed in the parameters, 
 * and applying it to every link in our linked list.*/

/* First we check to make sure our parameter of function f is not NULL.*/

/* If it is not NULL we start our loop through our linked list applying
 * function f to each link. Once it has been applied we set the current
 * link to be it's element next, setting it to the following link and
 * then starting the loop over again until we reach the end by hitting
 * NULL.*/
