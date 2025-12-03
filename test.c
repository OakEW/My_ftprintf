#include <stdio.h>
#include "./include/ft_printf.h"


int	main(void)
{
	printf (":_std_return = %d\n", printf ("%%%%%"));
	printf ("--------\n");
	printf (":__ft_return = %d\n", ft_printf ("%%%%%"));

	printf (":_std_return = %d\n", printf ("%s", NULL));
	printf ("--------\n");
	printf (":__ft_return = %d\n", ft_printf ("%s", NULL));
}
