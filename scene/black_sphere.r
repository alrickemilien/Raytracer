camera:
{
	from: (0 10 10)
	to: (0 0 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (4)
			position: (0 0 6)
			color: (0x8809)
		}
		sphere:
		{
			rayon: (4)
			position: (0 0 0)
			color: (0x8809)
		}
	}
	sphere:
	{
		rayon: (2)
		position: (0 0 3)
		color: (0x880009)
	}
}

csg:
{
	type: (intersection)
	sphere:
	{
		rayon: (1)
		position: (0 0 3.3)
		texture: (sphere/metal.xpm)
		resize_texture: (10)
	}
	sphere:
	{
		rayon: (1)
		position: (0 0 3)
		texture: (sphere/metal.xpm)
		resize_texture: (10)
	}
}

sphere:
{
	position: (0 0 0)
	rayon: (30)
	color: (0x213051)
	texture: (skybox/the_universe.xpm)
}

light:
{
	position: (1.2 0 5)
	intensity: (4)
}

plan:
{
	position: (0 0 20)
	normal: (0 0 1)
	color: (0x850009)
}

plan:
{
	position: (0 -30 0)
	normal: (0 1 0)
	color: (0x5585)
}
