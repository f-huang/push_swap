/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 17:36:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>
# include <stddef.h>

int		get_biggest_number_in_pile(t_pile pile);
int		get_tab_median(int *tab, uint16_t len);
int		is_a_correctly_sorted(t_game *game);
void	is_middle_of_a_is_sorted(t_game *game, int nb_rotate);
int		is_there_numbers_greater_than_median(t_pile pile, int median);
void	print_piles(t_game game);
void	resolve_game(t_game *game, uint16_t len, int from_sort_b);
void	sort_a_if_three_items(t_game *game);
void	swap_if_needed(t_game *game, int nb_rotate);

#endif
