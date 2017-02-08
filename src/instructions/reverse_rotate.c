/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:53:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 19:05:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_rotate(int **pile, int len)
{
	int		tmp;
	int		i;

	if (!*pile || len < 2)
		return ;
	tmp = (*pile)[len - 1];
	i = 0;
	while (i < len - 1)
	{
		(*pile)[i + 1] = (*pile)[i];
		++i;
	}
	(*pile)[0] = tmp;
}
