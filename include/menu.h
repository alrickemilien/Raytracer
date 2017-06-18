/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbellahc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:38:36 by wbellahc          #+#    #+#             */
/*   Updated: 2017/05/06 13:38:38 by wbellahc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H
# include "commun_struct.h"

typedef struct		s_data_draw
{
	int				error;
	int				x;
	int				size_x;
	int				size_y;
	int				tmp_x;
	int				tmp_y;
	int				limit_x;
	int				edge_x1;
	int				edge_y1;
	int				edge_x2;
	int				edge_y2;
	int				y;
	int				limit_y;
	int				edge;
	t_color			color1;
	t_color			color2;
	t_color			color3;
	char			*path;
	t_image			*picture;
}					t_data_draw;

void				reset_menu(t_menu *menu);
void				loop_menu(t_menu *menu);
void				reset_scene(t_menu *menu, char *path);
t_data_draw			params_data_draw(t_menu *menu);
t_data_draw			params_draw_scene(
					t_menu *menu, int pos, int marge, char *path);
void				draw_list(t_menu *menu);
t_color				mlx_put_xpm(int u, int v, t_image texture);
void				draw_menu(t_data_draw draw, t_image *image);
void				init_scene(t_menu *menu, char *path);

#endif
