/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:51:07 by aperrein          #+#    #+#             */
/*   Updated: 2023/05/09 09:57:12 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_p
{
	int				id;
	int				ate;
	long int		last_ate;
	struct s_all	*all;
	pthread_t		thr_id;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}	t_p;

typedef struct s_all
{
	int				n_p;
	int				ti_die;
	int				ti_eat;
	int				ti_sleep;
	int				n_must_eat;
	int				dead;
	int				end;
	long int		ti_start;
	t_p				*ph;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_dead;
}	t_all;

int			ft_atoi(const char *nptr);
int			ft_exit(char *s);
int			init_arg(int ac, char *av[], t_all *all);
long int	timer(void);
void		*thread_routine(void *data);
void		print_status(char *s, t_p *ph);

#endif
