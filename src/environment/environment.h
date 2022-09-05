#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "../utils.h"

typedef struct s_environment t_environment;

struct s_environment
{
	t_philosopher	*philosopher;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				remained_food;
	pthread_mutex_t	*forks[2];
};

/**
 * @brief Create several (size of args[0]) environment objects
 * 
 * @param arg_count size of argument list
 * @param args Arguments that will be pass in objects
 * @param forks Forks that will be attached
 * @return t_environment* list of t_environment with size args[0]
 */
t_environment   \
*create_environments(int arg_count, int *args, pthread_mutex_t *forks);

/**
 * @brief Destroys current environment objects
 * 
 * @param environments that will be destroyed
 * @return 1 if destroys successfully
 */
int	        destroy_environments(t_environment *environments);

/**
 * @brief Create a fork list with 'count' size
 * 
 * @param count size of the list
 * @return int* fork list with size 'count'
 */
pthread_mutex_t	            *create_forks(int count);

/**
 * @brief Destroys fork list
 * 
 * @param forks list to be destroy
 * @return 1 if destroys succesfully
 */
int             destroy_forks(pthread_mutex_t *forks, int count);

#endif