#include "menu.h"
#include "init.h"
#include <stdio.h>

static t_color	split_color_s(unsigned long color)
{
	t_color	color_split;

	color_split.red = (color & 0xFF0000) >> 16;
	color_split.green = (color & 0xFF00) >> 8;
	color_split.blue = (color & 0xFF);
	return (color_split);
}

t_data_draw		params_data_draw(t_menu *menu)
{
	t_data_draw draw;

	ft_bzero(&draw, (sizeof(t_data_draw)));
	draw.tmp_x = -1;
	draw.tmp_y = -1;
	draw.limit_x = menu->page->width;
	draw.limit_y = menu->page->height;
	draw.color1 = split_color_s(0x00555555);
	return (draw);
}

t_data_draw		params_data_draw_scene(t_menu *menu, int pos, int marge, char *path)
{
	t_data_draw draw;

    (void)menu;
	ft_bzero(&draw, (sizeof(t_data_draw)));
	draw.path = path;
	draw.nb_scene = pos;
	draw.tmp_x = (pos % 2) * 500 + 49;
	draw.tmp_y = marge * 250 + 99;
	draw.edge = 2;
	draw.size_x = 400;
	draw.size_y = 200;
	draw.limit_x = draw.tmp_x + draw.size_x + 2;
	draw.limit_y = draw.tmp_y + draw.size_y + 2;
	draw.edge_x1 = draw.limit_x - draw.edge;
	draw.edge_y1 = draw.limit_y - draw.edge;
	draw.edge_x2 = draw.tmp_x + draw.edge;
	draw.edge_y2 = draw.tmp_y + draw.edge;
	draw.color1 = split_color_s(0x00666666);
	draw.color2 = split_color_s(0x00888888);
	draw.color3 = split_color_s(0x00AAAAAA);
	return(draw);
}