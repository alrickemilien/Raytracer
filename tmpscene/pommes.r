camera:
{
	from: (0 15 0)
	to: (0 0 0)
}

camera:
{
	from: (0 15 8)
	to: (0 0 0)
}

camera:
{
	from: (-8 20 10)
	to: (0 0 0)
}

camera:
{
	from: (0 20 10)
	to: (0 0 0)
}

light:
{
	position: (0 30 30)
	intensity: (15)
}

plan:
{
	position: (0 0 0)
	normal: (0 0.2 1)
	color: (0xeeeeee)
	texture: (plan/parquet.xpm)
	resize_texture: (500)
}

csg:
{
	type: (intersection)
	sphere:
	{
		position: (0 0.8 0)
		rayon: (2.2)
		color: (0x47a35b)
		transparent: (0.2)
		reflection: (1)
		refraction: (1.1)
	}
	sphere:
	{
		position: (0 -0.3  0)
		rayon: (2.2)
		transparent: (0.2)
		reflection: (1)
		refraction: (1.1)
		color: (0x47a35b)
	}
	translation: (3 -2 4.6)
}
csg:
	{
		cylinder:
		{
			apex: (0 0 0)
			axis: (0 0 1)
			color: (0xffffffff)
			rayon: (0.08)
		}
		sphere:
		{
			position: (0 0 0)
			rayon: (3)
			color: (0xffffff)
		}
		translation: (3 -2 0)
	}

	csg:
	{
		type: (intersection)
		sphere:
		{
			position: (0 0.5 0)
			rayon: (1)
			color: (0xFFFFFF)
			transparent: (0.3)
			reflection: (1)
			refraction: (1.1)
		}
		sphere:
		{
			position: (0 -0.5  0)
			rayon: (1.6)
			transparent: (0.3)
			reflection: (1)
			refraction: (1.1)
			color: (0xFFFFFF)
		}
		translation: (-2 1 4.6)
	}
	csg:
	{
		cylinder:
		{
			apex: (0 0 0)
			axis: (0 0 1)
			color: (0xffffffff)
			rayon: (0.08)
		}
		sphere:
		{
			position: (0 0 0)
			rayon: (3)
			color: (0xffffff)
		}
		translation: (-2 1 0)
	}

	csg:
	{
		type: (intersection)
		sphere:
		{
			position: (0 0.5 0)
			rayon: (1.5)
			color: (0x565065)
		}
		sphere:
		{
			position: (0 -0.5  0)
			rayon: (1.5)
			color: (0x454054)
			transparent: (0.9)
			reflection: (1)
			refraction: (1.2)
		}
		translation: (0 1 3)
	}
	csg:
	{
		cylinder:
		{
			apex: (0 0 0)
			axis: (0 0 1)
			color: (0xffffffff)
			rayon: (0.08)
		}
		sphere:
		{
			position: (0 0 0)
			rayon: (2)
			color: (0xffffff)
		}
		translation: (0 1 0)
	}

	csg:
	{
		cylinder:
		{
			apex: (0 0 0)
			axis: (0 0 1)
			color: (0xffffffff)
			rayon: (0.08)
		}
		sphere:
		{
			position: (0 0 0)
			rayon: (2)
			color: (0xffffff)
		}
		translation: (0 1 0)
	}
	csg:
	{
		cylinder:
		{
			apex: (0 0 0)
			axis: (0 0 1)
			color: (0xffffffff)
			rayon: (0.08)
		}
		sphere:
		{
			position: (0 0 0)
			rayon: (2)
			color: (0xffffff)
		}
		translation: (0 1 0)
	}

csg:
	{
		type: (difference)
		sphere:
		{
			position: (0 0.5 0)
			rayon: (1.5)
			color: (0x565065)
		}
		sphere:
		{
			position: (0 -0.5  0)
			rayon: (1.5)
			color: (0x454054)
		}
		translation: (3 1 4)
	}

sphere:
{
	position: (0 0 0)
	rayon: (10000)
	color: (0x31a0d6)
	texture: (skybox/the_universe.xpm)
}
light: 
{
	position: (-0.2 0 7)
	intensity: (7)
}
