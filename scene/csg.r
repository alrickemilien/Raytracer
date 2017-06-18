camera:
{
	from:(0 0 0)
	to: (0 0 1)
}

camera:
{
	from:(3 3 6)
	to: (1 0 0)
}

plan:
{
	position: (5 -2 0)
	normal: (0 1 0)
}

csg:
{
	type: (intersection)
	cylinder:
		{
			apex: (1.5 0 0)
			axis: (0 0.5 0.2)
			color: (0x120aa2)
			rayon: (0.2)
		}
		sphere:
		{
			position: (1.5 0 0)
			color: (0x120aa2)
			rayon: (0.9)
		}
		
}
	
sphere:
{ 
	position: (1 1 1)
	rayon: (0.1)
	color: (0x6aa22) 
}

light:
{
	position: (0 5 -1)
	intensity: (5)
}
