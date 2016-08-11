/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_instruc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 20:22:16 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 21:40:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_instruc(char *instruc)
{
	char const	*tab[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",\
							"rra", "rrb", "rrr", NULL};
	int			i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(instruc, tab[i]) == 0)
			return (i);
		i++;
	}
	ft_putendl_fd("Error", 2);
	return (-1);
}

static void	play_instruc(t_game *game, char *instruc, int ret)
{
	if (ret >= 0 && ret < 3)
		swap(ft_strrchr(instruc, 'a') ? &game->pile_a : &game->pile_b);
	else if (ret >= 5 && ret < 8)
		rotate(ft_strrchr(instruc, 'a') ? &game->pile_a : &game->pile_b);
	else if (ret >= 8 && ret < 11)
		reverse(ft_strrchr(instruc, 'a') ? &game->pile_a : &game->pile_b);
	if (ret == 2)
		swap(&game->pile_a);
	else if (ret == 7)
		rotate(&game->pile_a);
	else if (ret == 10)
		reverse(&game->pile_a);
	else if (ret == 3)
		push(&game->pile_a, &game->pile_b);
	else if (ret == 4)
		push(&game->pile_b, &game->pile_a);
}

void		follow_instruc(t_game *game, char *instruc)
{
	int			ret;

	if ((ret = is_valid_instruc(instruc)) == -1)
		return ;
	play_instruc(game, instruc, ret);
		print(game->pile_a);
		print(game->pile_b);
}
