/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_items.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:31:52 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 21:49:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "game.h"
// #include "libft.h"
// extern int	total;
//
// void	sort_three_items(int **pile, uint16_t len)
// {
// 	if (len != 3 || is_pile_sorted(*pile, len))
// 		return ;
// 	else if (is_pile_reverse_sorted(*pile, len))
// 	{
// 		swap(pile, len);
// 		reverse_rotate(pile, len);
// 		total += 2;
// 	}
// 	else if ((*pile)[0] < (*pile)[1])
// 	{
// 		reverse_rotate(pile, len);
// 		++total;
// 		if (!is_pile_sorted(*pile, len) && (*pile)[0] < (*pile)[2])
// 		{
// 			++total;
// 			swap(pile, len);
// 		}
// 	}
// 	else
// 	{
// 		if ((*pile)[0] < (*pile)[2])
// 			swap(pile, len);
// 		else
// 		{
// 			++total;
// 			reverse_rotate(pile, len);
// 			reverse_rotate(pile, len);
// 		}
// 		++total;
// 	}
//
// }
