/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/14 19:16:22 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>

void	init_sorted_pile(int **sorted_pile, int *pile_a, int len);
void	resolve_game(t_piles *piles, uint16_t len);

int		get_tab_median(int *tab, uint16_t len);


void	print_piles(t_piles *piles);

#endif
