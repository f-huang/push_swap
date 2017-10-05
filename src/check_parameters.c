/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:12:51 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/05 14:36:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

static char	**ft_tabjoin(char **tab1, char **tab2)
{
	int		i;
	int		j;
	char	**ret;

	if (!(ret = (char**)ft_memalloc(sizeof(char*) *\
		(ft_tablen(tab1) + ft_tablen(tab2) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (tab1 && tab1[i])
		ret[j++] = (tab1[i++]);
	i = 0;
	while (tab2 && tab2[i])
		ret[j++] = (tab2[i++]);
	ret[j] = NULL;
	if (tab1)
		free(tab1);
	tab1 = NULL;
	return (ret);
}

static char	**get_parameters(char **av)
{
	int		i;
	char	**tmp;
	char	**tab;

	i = 0;
	tmp = NULL;
	tab = NULL;
	if (!av[0])
		tab = ft_memalloc(sizeof(char*) * 1);
	while (av && av[i])
	{
		tmp = ft_strsplit(av[i], ' ');
		tab = ft_tabjoin(tab, tmp);
		++i;
		if (!tab || !tmp)
			break ;
		free(tmp);
		tmp = NULL;
	}
	return (tab);
}

char		**check_parameters(t_game *game, char **av, int *len)
{
	int		i;
	int		j;
	int		tmp;
	char	**tab;

	if ((i = get_options(game, av)) == -1)
		return (NULL);
	tab = get_parameters(av + i);
	i = 0;
	while (tab && tab[i])
	{
		if (!ft_isint(tab[i]) || !ft_isstrdigit(tab[i]))
			return (NULL);
		j = 1;
		while (tab[j])
		{
			tmp = ft_atoi(tab[i]);
			if (i != j && tmp == ft_atoi(tab[j]))
				return (NULL);
			++j;
		}
		++i;
	}
	*len = tab ? ft_tablen(tab) : 0;
	return (tab);
}
