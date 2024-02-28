/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:19:40 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/08 14:19:41 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

t_list	*ll_new(void *data)
{
	t_list	*ll;

	ll = (t_list *)malloc(1 * sizeof(t_list));
	if (ll == NULL)
		return (NULL);
	ll->data = data;
	ll->next = NULL;
	return (ll);
}

void	ll_add_head(t_list **list, t_list *new)
{
	t_list	*head;

	head = *list;
	*list = new;
	(*list)->next = head;
}

void	ft_ll_clear(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	if (!list || !(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
	*list = NULL;
}
