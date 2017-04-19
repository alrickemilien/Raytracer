#include "stdlib.h"
#include "stdio.h"
#include "../libft/libft.h"
#include "../../include/vector.h"
# include <time.h>


double	myrand(double min, double max)
{
	double	diff;
	double	cutoff;

	range = max - min + 1;
	cutoff = (RAND_MAX / range) * range;
	res = 
	while (res >= cutoff)
	{
		res = rand();
	}
	return (res % range + min);
}

void	generate_noise(t_vector *gradient_array)
{
	int			i;

	i = 0;
	while (i < 100)
	{
		set_vec(&gradient_array[i], myrand(-1, 1), myrand(-1, 1) - 1, myrand(-1, 1));
		i++;
	}
}

int		main()
{
	t_vector	array[100];
	int		i;

	srand(time(NULL));
	ft_bzero(array, sizeof(t_vector) * 100);
	generate_noise(array);
	i = 0;
	while (i < 100)
	{
		printf("x = %lf -- y = %lf -- z = %lf\n", array[i].x, array[i].y, array[i].z);
		i++;
	}
	return (0);
}
