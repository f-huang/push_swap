/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both_piles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:19:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 13:22:42 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	reverse_rotate_both_piles(t_piles *piles)
{
	reverse_rotate(&piles->pile_a, piles->len_a);
	reverse_rotate(&piles->pile_b, piles->len_b);
}
