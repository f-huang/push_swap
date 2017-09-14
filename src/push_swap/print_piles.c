#include "game.h"
#include "push_swap.h"
#include "libft.h"

void	print_piles(t_piles *piles)
{
	ft_putstrcol(" A : ", GREEN);
	for (int i = 0 ; i < piles->len_a; i++)
	{
		ft_printf("%d ", piles->pile_a[i]);
	}
	ft_putstrcol("\n B : ", GREEN);
	for (int i = 0 ; i < piles->len_b; i++)
	{
		ft_printf("%d ", piles->pile_b[i]);
	}
	ft_putchar('\n');
}
