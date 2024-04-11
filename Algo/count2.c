/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:08:43 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:14:06 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_r(t_list **search, int countra, int countrb)
{
	if ((*search)->ra <= (*search)->rra && (*search)->rb <= (*search)->rrb)
	{
		countra = (*search)->ra;
		countrb = (*search)->rb;
		while (countra != 0 && countrb != 0)
		{
			countra -= 1;
			countrb -= 1;
			(*search)->rr += 1;
		}
	}
}
