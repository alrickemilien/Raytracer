camera:
{
	from:(-3 2 0)
	to: (1 0 0)
}

camera:
{
	from:(3 3 6)
	to: (1 0 0)
}

plan:
{
	position: (5 0 0)
	normal: (0 1 0)
}

csg:
{
	type: (intersection)
	sphere:
	{
		position: (2 0 0)
		rayon: (0.5)
		diffuse: (0.1)
		specular: (0.1)
		color: (0x120aa2)
	}
	sphere:
	{
		position: (2 -0.3 0)
		color: (0x120aa2)
		rayon: (0.6)
	}
	color: (0x120aa2)
}
	
sphere:
{ 
	position: (1 1 1)
	rayon: (0.1)
	color: (0x6aa22) 
}

light:
{
	position: (0 1 -1)
	intensity: (5)
}
