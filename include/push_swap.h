/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:26:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>
# include <stddef.h>

# define GAME_PRINT_INSTRUCTION 1

void	set_sorted_pile(t_pile *sorted, t_pile a, int max_size);
void	resolve_game(t_game *game, uint16_t len, int from_sort_b);

int		get_tab_median(int *tab, uint16_t len);

// int		are_smaller_number_at_the_start(int *pile, uint16_t len, int median);
// void	sort_three_items(int **pile, uint16_t len);

void	print_piles(t_game game);

#endif
