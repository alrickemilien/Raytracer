camera:
{
	from: (0 9 9)
	to: (0 0 0 )
}

camera:
{
	from: (0 0 30)
	to: (0 0 0 )
}

camera:
{
	from: (0 0 12)
	to: (0 0 0 )
}

light:
{
	position: (0 30 30)
	intensity: (7)
}

light:
{
	position: (-2 1 3)
	intensity: (3)
}

sphere:
{
	rayon: (0.2)
	position: (0.5 -0.5 1.6)
	color: (0xffffff)
	reflection: (1)
}

plan:
{
	position: (0 0 40)
	normal: (0 0 1)
	color: (0x00)
}

sphere:
{
	rayon: (0.05)
	position: (0.4 -0.5 1.8)
	color: (0x0)
}

csg:
{
	type: (difference)
	sphere:
	{
		position: (1 0 1)
		rayon: (1)
		color: (0xead13b)
		brillance: (1)
		specular: (1)
		reflection: (0.1)

	}
	box:
	{
		position: (0 1 1)
		size: (1)
		color: (0xead13b)
		rotation: (0 0 90)
	}
}

plan:
{
	position: (0 0 0)
	normal: (0 0 1)
}

box:
{
	color: (0x0)
	size: (10)
	position: (7 11 -8)
	rotation: (0 0 30)
}

box:
{
	color: (0x0)
	size: (10)
	position: (-7 -10 -8)
	rotation: (0 0 30)
}

plan:
{
	position: (0 0 200)
	color: (0xffffff)
	normal: (0 0 1)
}

cylinder:
{
	apex: (-3 2 0.5)
	axis: (0 0 1)
	color: (0x982ac9)
	size: (1)
	rayon: (0.5)
}

sphere:
{
	position: (-3 2 1)
	color: (0x982ac9)
	rayon: (0.5)
}

sphere:
{
	rayon: (0.2)
	position: (-3.4 1.9 1)
	color: (0xffffff)
}

sphere:
{
	rayon: (0.05)
	position: (-3.55 1.9 1.1)
	color: (0x0)
}

sphere:
{
	rayon: (0.2)
	position: (-3.15 2.4 1)
	color: (0xffffff)
}

sphere:
{
	rayon: (0.05)
	position: (-3.23 2.55 1.1)
	color: (0x0)
}
