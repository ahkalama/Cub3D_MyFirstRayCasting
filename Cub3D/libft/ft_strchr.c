/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:58:05 by ahkalama          #+#    #+#             */
/*   Updated: 2024/02/10 13:58:06 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	if (c > 127)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == c)
			return ((char *)(s1));
		s1++;
	}
	if (c == '\0')
		return ((char *)s1);
	return ((char *)0);
}
