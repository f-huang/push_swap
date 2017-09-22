/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both_piles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:19:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 23:54:45 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	reverse_rotate_both_piles(t_pile *a, t_pile *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
