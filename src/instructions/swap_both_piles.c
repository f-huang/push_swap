/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both_piles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:18:48 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 13:22:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	swap_both_piles(t_piles *piles)
{
	swap(&piles->pile_a, piles->len_a);
	swap(&piles->pile_b, piles->len_b);
}
