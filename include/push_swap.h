/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 14:54:50 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <inttypes.h>
# include <stddef.h>

void	resolve_game(t_game *game, uint16_t len, int from_sort_b);

int		get_tab_median(int *tab, uint16_t len);

void	print_piles(t_game game);

void	swap_if_needed(t_game *game);

#endif
