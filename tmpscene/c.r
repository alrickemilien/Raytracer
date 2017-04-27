camera:
{
	from: (10 10 8)
	to: (0 0 0 )
}

light:
{
	position: (0 60 50)
	intensity: (7)
}

light:
{
	position: (-50 -100 50 )
	intensity: (80)
}

light:
{
	position: (-3 -5 4)
	intensity: (0.5)
}

csg:
{
	type: (difference)
	sphere:
	{
		rayon: (2)
	}
	box:
	{
		position: (0 1.5 1.5)
		reflection: (1)
		refraction: (1)
		size: (1)
	}
}
