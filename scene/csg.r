camera:
{
	from:(0 0 0)
	to: (1 0 0)
}

plan:
{
	position: (5 0 0)
	normal: (0 1 0)
}

csg:
{
	type: (union)
	csg:
	{	
		type: (difference)
		sphere:
		{
			position: (3 0 0)
			rayon: (0.5)
			color: (0x120aa2)
		}
	}
	sphere:
	{
		position: (0 0 0)
		rayon: (0.2)
		color: (0xff0000)
	}
	color: (0x0ff)
}

sphere:
{ 
	position: (1 1 1)
	rayon: (0.1)
	color: (0x6aa22) 
}
