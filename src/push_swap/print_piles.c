#include "game.h"
#include "push_swap.h"
#include "libft.h"

void	print_piles(t_game game)
{
	ft_putstrcol(" A : ", GREEN);
	for (int i = 0 ; i < game.a.len; i++)
	{
		ft_printf("%d ", game.a.list[i]);
	}
	ft_putstrcol("\n B : ", GREEN);
	for (int i = 0 ; i < game.b.len; i++)
	{
		ft_printf("%d ", game.b.list[i]);
	}
	ft_putchar('\n');
}
