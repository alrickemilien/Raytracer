scene:
{
	antialiasing: (yes)
	ambient: (0.3)
}

camera:
{
	from: (0 8 10)
	to: (0 0 0)
}

camera:
{
	from: (0 25 10)
	to: (0 0 0)
}

light:
{
	position: (10 10 10)
	shining: (yes)
	intensity: (5)
}

plan:
{
	normal: (0 0 1)
	reflection: (0.7)
	refraction: (0.3)
	diffuse: (0.9)
}

sphere:
{
	position: (0 0 0)
	color: (0x76e78f)
	rayon: (2.5)
	reflection: (1)
}

cone:
{
	rotation: (-60 0 0)
	color: (0xaa0000)
	apex: (5 0 2)
	reflection: (0.4)
	axis: (0.5 0.5 0)
}

plan:
{
	position: (0 0 50)
	color: (0x111111)
	normal: (0 0 1)
}

plan:
{
	position: (0 50 0)
	color: (0xabdf52)
	normal: (0 1 1)
	reflection: (0.3)
	texture: (plan/damier.xpm)
}
