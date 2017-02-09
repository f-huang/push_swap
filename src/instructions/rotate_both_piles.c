/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both_piles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:19:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 13:22:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	rotate_both_piles(t_piles *piles)
{
	rotate(&piles->pile_a, piles->len_a);
	rotate(&piles->pile_b, piles->len_b);
}
