/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:47:15 by namalier          #+#    #+#             */
/*   Updated: 2024/03/05 16:12:13 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_list **n, int yn)
{
	t_list	*swap;
	t_list	*tmp;

	swap = (*n);
	if ((*n)->next->next == NULL)
		sb(n, 0);
	else
	{
		while (swap->next->next)
			swap = swap->next;
		tmp = swap;
		swap = swap->next;
		ft_lstadd_front(n, swap);
		tmp->next = NULL;
	}
	if (yn == 1)
		write (1, "rrb\n", 4);
	return ;
}
