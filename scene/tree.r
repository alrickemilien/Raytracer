camera:
{
	from: (0 0 -1)
	to: (0 0 1)
}

camera:
{
	from: (0 0 8)
	to: (-3 3 8.3)
}

camera:
{
	from: (-1 1 -1)
	to: (0 0 8)
}

plan:
{
	position: (0 -0.7 10)
	color: (0xddccdc)
	normal: (0 0.5 -0.2)
}
csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		cone:
		{
			apex: (0 0 8)
			axis: (-1 1 -0.1)
			angle: (35)
			refraction: (1.1)
			reflection: (1)
			transparent: (0.9)
			color: (0xFEF65B)
		}
		sphere:
		{
			position: (0 0 8)
			rayon: (3.9)
			color: (0x3281C6)
		}
		color: (0xcd01c9)
	}
	sphere:
	{
		position: (0 0 8)
		rayon: (0.1)
		color: (0xcd01c9)
	}
	color: (0xcd01c9)
}

cone:
{
	apex: (0 0 8)
	axis: (1 1 -0.1)
}

sphere:
{
	rayon: (0.9)
	position: (-3 3 8.3)
	color: (0x02cc09)
	refraction: (1)
	reflection: (1)
	transparent: (0.2)
}

light:
{
	position: (0 3 3)
	intensity: (5.5)
}
