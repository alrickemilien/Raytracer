scene:
{
	ambient: (0.5)
	antialiasing: (no)
}

camera:
{
	from: (10 10 8)
	to: (0 0 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (5.5)
		}
		plan:
		{
			normal: (-1 -2 2)
		}
	}
	sphere:
	{
		rayon: (5.3)
	}
	translation: (0 3 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (3.5)
		}
		plan:
		{
			normal: (-1 -2 2)
		}
	}
	sphere:
	{
		rayon: (3.3)
	}
	translation: (0 3 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (4)
		}
		plan:
		{
			normal: (-1 -2 2)
		}
	}
	sphere:
	{
		rayon: (3.8)
	}
	translation: (0 3 0)
}

sphere:
{
	rayon: (2.5)
	color: (0x0f6b56)
	translation: (0 3 0)
	refraction: (1)
	reflection: (0.2)
	transparent: (0.3)
}

light:
{
	position: (-50 -100 50 )
	intensity: (80)
}

sphere:
{
	rayon: (0.5)
	position: (-3 -2 3)
	color: (0x738187)
}

plan: 
{
	normal: (1 1 1)
	position: (-150 -150 -150)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (5)
		}
		plan:
		{
			normal: (6 3 2)
			color: (0x6D0610)
			refraction: (1)
			reflection: (0.2)
		transparent: (0.9)
		}
	}
	sphere:
	{
		rayon: (4.4)
	}
	translation: (-3 -5 0)
	}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (4.1)
		}
		plan:
		{
			normal: (6 3 2)
			color: (0x6D0610)
		}
	}
	sphere:
	{
		rayon: (3.9)
	}
	translation: (-3 -5 0)
	}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (2.5)
		}
		plan:
		{
			normal: (-1 -2 2)
		}
	}
	sphere:
	{
		rayon: (2.3)
	}
	translation: (-3 -5 0)
}

csg:
{
	type: (difference)
	csg:
	{
		type: (intersection)
		sphere:
		{
			rayon: (3)
		}
		plan:
		{
			normal: (1 -2 2)
		}
	}
	sphere:
	{
		rayon: (2.8)
	}
	translation: (-3 -5 0)
}

sphere:
{
	rayon: (1.5)
	color: (0x0f6b56)
	translation: (-3 -5 0)
}

sphere:
{

	position: (11 9 9)
}
