/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:02:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>
# include <stddef.h>

void	resolve_game(t_game *game, uint16_t len, int from_sort_b);

int		get_tab_median(int *tab, uint16_t len);

void	print_piles(t_game game);

int		is_a_correctly_sorted(t_game *game);
int		is_there_numbers_greater_than_median(t_pile pile, int median);
void	swap_if_needed(t_game *game);

#endif
