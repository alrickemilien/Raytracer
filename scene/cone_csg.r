camera:
{
<<<<<<< HEAD
	from:(-20 2 0)
=======
	from:(-20 20 0)
>>>>>>> c0a99ba245166d1266767ce9f4d6b20a82e0bf8d
	to: (1 0 0)
}

camera:
{
<<<<<<< HEAD
	from:(30 30 6)
=======
	from:(60 60 0)
>>>>>>> c0a99ba245166d1266767ce9f4d6b20a82e0bf8d
	to: (1 0 0)
}

plan:
{
	position: (5 -5 0)
	normal: (0 1 0)
}

csg:
{
	type: (intersection)
	cylinder:
	{
		apex: (2 0.5 0)
		axis: (0 1 1)
		color: (0x120aa2)
		rayon: (1.2)
	}
	cylinder:
	{
		apex: (2 0.5 0)
		axis: (0 1 0.5)
		color: (0x120aa2)
		rayon: (1.5)
	}
	color: (0x800332)
	specular: (0.9)
	diffuse: (0.1)
}


light:
{
	position: (-10 8 0)
	intensity: (30)
}
