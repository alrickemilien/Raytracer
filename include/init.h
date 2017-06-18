/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:38:19 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:38:21 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <pthread.h>
# include "commun_struct.h"

void				*init_data_tab_thread(
					const char *params, size_t size, int nb_thread);
int					init_default_camera(t_env *env);
pthread_t			*init_thread(int nb_thread);
t_image				*init_image(void *addr_mlx, int width, int height);
t_image				*init_texture(void *addr_mlx, char *path);
void				init_env(t_env *env);
t_menu				*creat_menu(void);

#endif
