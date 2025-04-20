#include "philo.h"

void	*monitoring(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		for (int i = 0; i < table->n_philo; i++)
		{
			pthread_mutex_lock(&table->table_lock);
			if (get_curr_time()
				- table->philos[i].time_last_eat > table->time_to_die)
			{
				print_action(&table->philos[i], "died");
				table->dead = 1;
				pthread_mutex_unlock(&table->table_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&table->table_lock);
		}
		ft_usleep(1);
	}
	return (NULL);
}
