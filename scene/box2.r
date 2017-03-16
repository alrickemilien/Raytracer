camera:
{
	from: (0 10 10)
	to: (0 0 0)
}

csg:
{
	type: (difference)
	box:
	{
		position: (1 0 4)
		size: (3)
		color: (0xff0000)
	}
	sphere:
	{
		rayon: (2)
		position: (0 0 3)
		color: (0x880009)
	}
}

plan:
{
	position: (0 0 0)
	normal: (0 0 1)
	color: (0x213051)
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
