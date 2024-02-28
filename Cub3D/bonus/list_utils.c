/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:28:59 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/08 15:29:00 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

t_object	*ft_create_obj(int frame, int x, int y)
{
	t_object	*new;

	new = (t_object *)malloc(1 * sizeof(t_object));
	if (new == NULL)
		return (NULL);
	new->x = (double)x;
	new->y = (double)y;
	new->frame = (double)frame;
	return (new);
}

int	ft_ll_find(t_list *head, int x, int y)
{
	t_object	*temp;

	while (head)
	{
		temp = head->data;
		if (temp->x == x && temp->y == y)
			return ((int)temp->frame);
		head = head->next;
	}
	return (0);
}

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

void	ft_ll_remove(t_list **list, int x, int y)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (((t_object *)tmp->data)->x == x && ((t_object *)tmp->data)->y == y)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*list = tmp->next;
			free(tmp->data);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
