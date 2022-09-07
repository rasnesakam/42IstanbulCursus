
#include "../utils.h"

void philo_print(t_philosopher philosopher, char *message)
{
	unsigned long long	timestamp;
	int					id;

	timestamp = get_timestamp(0);
	id = philosopher.id;
	printf("%llu %d %s\n",timestamp, id, message);
}