/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:36:26 by fgabler           #+#    #+#             */
/*   Updated: 2023/10/15 20:03:02 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_test
{
	pthread_mutex_t			mutex;
	int						num;
}	t_test;

void	*routine(void *arg);

int	main(int ac, char **av)
{
	pthread_t	th[11];
	t_test		*test;

	test = malloc(sizeof(t_test));
	test->num = 0;
	pthread_mutex_init(&test->mutex, NULL);
	int			i;

	i = 0;
	while (i < 11)
	{
		if (pthread_create(th + i, NULL, &routine, test) != 0)
			perror("Failed to create thread");
		i++;
	}
	i = 0;
	while (i < 11)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&test->mutex);
	free(test);
	return (0);
}

void	*routine(void *arg)
{
	t_test *test;
	test = (t_test *) arg;
	pthread_mutex_lock(&test->mutex);
	printf("NUM: %d\n", test->num++);
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
	printf("TIME: %d\n", tv.tv_usec);
	pthread_mutex_unlock(&test->mutex);
	return arg;
}
