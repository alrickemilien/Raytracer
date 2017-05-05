camera:
{
	from: (0 -8 6)
	to: (0 10 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (6)
			position: (0 10 4)
			color: (0x8809)
			texture: (sphere/metal.xpm)
			reflection: (0.3)
			resize_texture: (2)
		}
		sphere:
		{
			rayon: (6)
			position: (0 10 -6)
			color: (0x8809)
			texture: (sphere/metal.xpm)
			reflection: (0.3)
			resize_texture: (2)
		}
	}
	sphere:
	{
		rayon: (2)
		position: (0 10 -1)
		color: (0x00ffcc)
		reflection: (1)
	}
}

sphere:
{
	rayon: (1.5)
	position: (0 10 1)
	reflection: (1)
	refraction: (1)
	color: (0x00)
	transparent: (0.1)
}

sphere:
{
	position: (0 -10 0)
	rayon: (25)
	color: (0x213051)
	transparent: (0.5)
	reflection: (0.1)
	texture: (skybox/the_universe.xpm)
}

light:
{
	position: (0 28 0)
	intensity: (100)
}

light:
{
	position: (0 -28 0)
	intensity: (100)
}
