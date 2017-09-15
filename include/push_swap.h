/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 16:03:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>
# include <stddef.h>

void	init_sorted_pile(int **sorted_pile, int *pile_a, int len);
void	resolve_game(t_piles *piles, uint16_t len, int from_sort_b);

int		get_tab_median(int *tab, uint16_t len);

int		are_smaller_number_at_the_start(int *pile, uint16_t len, int median);
void	sort_three_items(int **pile, uint16_t len);

void	print_piles(t_piles *piles);

#endif
