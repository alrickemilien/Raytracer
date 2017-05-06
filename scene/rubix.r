scene:
{
	ambient: (0.4)
}

camera:
{
	from: (0 70 70)
	to: (0 0 0)
}

camera:
{
	from: (0 15 10)
	to: (0 0 0)
}

plan:
{
	position: (0 0 -1)
	normal: (0 0 1)
}

plan:
{
	position: (0 0 120)
	normal: (0 0 1)
}


box:
{
	position: (0 0 0)
	color: (0x0ffff)
	transparent: (0.3)
	reflection: (1)
	refraction: (1.05)
	size: (1)
	rotation: (0 0 30)
}

box:
{
	position: (0 1 0)
	color: (0x0ffff)
	transparent: (0.3)
	reflection: (1)
	refraction: (1.05)
	size: (1)
	rotation: (0 0 30)
}

sphere:
{
	position: (0.5 0.5 2)
	rayon: (0.2)
	color: (0x5509)
}

csg:
{
	type: (intersection)
	cylinder:
	{
		apex: (0 0 0)
		rayon: (0.15)
		axis: (-0.5 0 -0.1)
		color: (0x2e0cc)
	}
	sphere:
	{
		position: (0 0 0)
		rayon: (6)
		color: (0x2e0cc)
	}
}

csg:
{
	type: (intersection)
	cylinder:
	{
		apex: (0 0 0)
		rayon: (0.1)
		axis: (0.5 0.5 -0.7)
		color: (0x2e0cc)
	}
	sphere:
	{
		position: (0 0 0)
		rayon: (9)
		color: (0x2e0cc)
	}
}

csg:
{
	type: (intersection)
	cylinder:
	{
		apex: (0 0 0)
		rayon: (0.15)
		axis: (-0.5 0 -0.1)
		color: (0x2e0cc)
	}
	sphere:
	{
		position: (0 0 0)
		rayon: (6)
		color: (0x2e0cc)
	}
}

csg:
{
	type: (intersection)
	cylinder:
	{
		apex: (0 0 0)
		rayon: (0.1)
		axis: (0.8 -0.8 0.1)
		color: (0x2e0cc)
	}
	sphere:
	{
		position: (0 0 0)
		rayon: (9)
		color: (0x2e0cc)
	}
}

sphere:
{
	position: (0 -20 0)
	rayon: (6)
	color: (0x2e0aa)
}

light:
{
	position: (0 -20 1)
	shining: (yes)
	intensity: (4)
}


box:
{
	position: (0.5 0.5 0.5)
	color: (0x0ff0000)
	size: (1)
	rotation: (0 0 30)
}

light:
{
	type: (cone)
	axis: (0 0 1)
	angle: (1)
	intensity: (5)
	position: (0 0 5)
}

light:
{
	type: (cone)
	axis: (0 0 1)
	angle: (1)
	intensity: (8)
	position: (0 0 30)
}

light:
{
	type: (cone)
	axis: (0 1 0)
	angle: (0.4)
	intensity: (10)
	position: (0 0 5)
}
