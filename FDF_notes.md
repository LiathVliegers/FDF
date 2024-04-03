Great sources:

miniLibX:
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

MLX42:
https://github.com/codam-coding-college/MLX42/blob/master/README.md


good github page:
https://github.com/ailopez-o/42Barcelona-FdF/blob/main/README.md


TODO's:


- 
- in main function: its better an less buggy to check if esc key is down in mlx_loop_hook, instead of in ft_hook (this is usefull if you want to check if for example the ctrl key is being hld down) -> ask Maarten





VINCENTS TIPS:
void	exit_error(t_data *data, char *msg)
{
	clean_up(data);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
void	*ft_malloc(t_data *data, size_t size)
{
	void	*thingy;
	thingy = malloc(size);
	if (thingy == NULL)
		exit_error(data, "malloc failed");
	return (thingy);
}




r = 81
g = 02
b = 02
a = FF
0x810202FF

r << 24 | g << 16 | b << 8 | a;


structs dereferencing   (:S)
(*map).height			= map->height
(*(points_row + i)).z	= points_row[i].z






Bresenham's Line Drawing Algorithm - Lines in all octants

m = slope

1. X1 < X2		&&		0 <= m <= 1
2. Y1 < Y2		&&		1 < m < infinity
3. Y1 < Y2		&&		-1 > m > -infinity
4. X2 < X1		&&		0 >= m >= -1
5. X2 < X1		&&		0 < m <= 1
6. Y2 < Y1		&&		1 < m < infinity
7. Y2 < Y1		&&		-1 > m > -infinity
8. X1 < X2		&&		0 >= m >= -1

Octant 1: 		Do Nothing

Octant 2: 		swap X1, Y1
				swap X2, Y2
				put_pixel(Y,X)

Octant 3: 		swap X1, Y1
				swap X2, Y2
				Y *= -1
				put_pixel(Y,X)

Octant 4: 		X *= -1
				put_pixel(X,Y)

Octant 5: 		Y *= -1
				X *= -1
				put_pixel(X,Y)

Octant 6: 		swap X1, Y1
				swap X2, Y2
				Y *= -1
				X *=* -1
				put_pixel(Y,X)

Octant 7: 		swap X1, Y1
				swap X2, Y2
				X *= -1
				put_pixel(Y,X)

Octant 8: 		Y *= -1
				put_pixel(X,Y)



EXAMPLE:

point 1 = [32, 3]
point 2 = [48, 8]
slope = (8-3) / (48-32) = 0,3125
X1 < X2 (32 < 48) and (0 <= m <= 1)
so the line is in the FIRST octant.

|	t	|	P	|	X	|	Y	|
|-------|-------|-------|-------|
|	0	|  -6   |	32	|	3	|	0
|	1	|   4   |	33	|	3	|
|	2	|  -18  |	34	|	4	|	1
|	3	|  -8   |	35	|	4	|
|	4	|   2   |	36	|	4	|
|	5	|  -20  |	37	|	5	|	2
|	6	|  -10  |	38	|	5	|
|	7	|   0   |	39	|	5	|
|	8	|  -22  |	40	|	6	|	3
|	9	|  -12  |	41	|	6	|
|	10	|  -2   |	42	|	6	|
|	11	|   8   |	43	|	6	|
|	12	|  -14  |	44	|	7	|	4
|	13	|  -4   |	45	|	7	|
|	14	|   6   |	46	|	7	|
|	15	|  -16  |	47	|	8	|	5
|	16	|  -6   |	48	|	8	|

dx			= 16
dy			= 5
2dy			= 10
2dy - 2dx 	= -22
P0 			= 2dy - dx
P0 			= -6


-------------
FIRST OCTANT:
point 1 = [32, 3]
point 2 = [48, 8]
slope = (8-3) / (48-32) = 0,3125
X1 < X2
Y1 < Y2
X1 < X2		&&		0 <= m <= 1

Octant 1: 		Do Nothing

-------------
SECOND OCTANT:
point 1 = [3, 32]
point 2 = [8, 48]
slope = (48-32) / (8-3) = 3,2
X1 < X2
Y1 < Y2
Y1 < Y2		&&		1 < m < infinity

Octant 2: 		swap X1, Y1
				swap X2, Y2
				put_pixel(Y,X)
SWAP
point 1 = [32, 3]
point 2 = [48, 8]

dx			= 16
dy			= 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6

-------------
THIRD OCTANT:
point 1 = [8, 32]
point 2 = [3, 48]
slope = (48-32) / (3-8) = −3,2
X2 < X1
Y1 < Y2
Y1 < Y2		&&		-1 > m > -infinity

Octant 3: 		swap X1, Y1
				swap X2, Y2
				Y *= -1
				put_pixel(Y,X)
SWAP
point 1 = [32, 8]
point 2 = [48, 3]

dx			= 16
dy			= -5	* -1 = 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6

-------------
FOURTH OCTANT:
point 1 = [48, 3]
point 2 = [32, 8]
slope = (8-3) / (32-48) = −0,3125
X2 < X1
Y1 < Y2
X2 < X1		&&		0 >= m >= -1

Octant 4: 		X *= -1
				put_pixel(X,Y)

dx			= -16	* -1 = 16
dy			= 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6

-------------
FIFTH OCTANT:
point 1 = [48, 8]
point 2 = [32, 3]
slope = (3-8) / (32-48) = 0,3125
X2 < X1
Y2 < Y1

X2 < X1		&&		0 < m <= 1

Octant 5: 		Y *= -1
				X *= -1
				put_pixel(X,Y)

dx			= -16	* -1 = 16
dy			= -5	* -1 = 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6

-------------
SIXTH OCTANT:
point 1 = [8, 48]
point 2 = [3, 32]
slope = (32-48) / (3-8) = 3,2
X2 < X1
Y2 < Y1

Y2 < Y1		&&		1 < m < infinity

Octant 6: 		swap X1, Y1
				swap X2, Y2
				Y *= -1
				X *=* -1
				put_pixel(Y,X)

SWAP
point 1 = [48, 8]
point 2 = [32, 3]

dx			= -16	* -1 = 16
dy			= -5	* -1 = 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6

---------------
SEVENTH OCTANT:
point 1 = [3, 48]
point 2 = [8, 32]
slope = (32-48) / (8-3) = −3,2
X1 < X2
Y2 < Y1

Y2 < Y1		&&		-1 > m > -infinity

Octant 7: 		swap X1, Y1
				swap X2, Y2
				X *= -1
				put_pixel(Y,X)

SWAP
point 1 = [48, 3]
point 2 = [32, 8]

dx			= -16 			* -1 = 16
dy			= 5
2dy			= 10
P0 			= 2dy - dx
P0 			= 10 -16 = 		-6

-------------
EIGTH OCTANT:
point 1 = [32, 8]
point 2 = [48, 3]
slope = (3-8) / (48-32) = −0,3125
X1 < X2
Y2 < Y1

X1 < X2		&&		0 >= m >= -1

Octant 8: 		Y *= -1
				put_pixel(X,Y)

dx			= 16
dy			= -5 			* -1 = 5
2dy			= 10
P0 			= 2dy - dx
P0 			= -6











|	t	|	P	|	X	|	Y	|
|-------|-------|-------|-------|
|	0	|       |	32	|		|
|	1	|       |	33	|		|
|	2	|       |	34	|		|
|	3	|       |	35	|		|
|	4	|       |	36	|		|
|	5	|       |	37	|		|
|	6	|       |	38	|		|
|	7	|       |	39	|		|
|	8	|       |	40	|		|
|	9	|       |	41	|		|
|	10	|       |	42	|		|
|	11	|       |	43	|		|
|	12	|       |	44	|		|
|	13	|       |	45	|		|
|	14	|       |	46	|		|
|	15	|       |	47	|		|
|	16	|       |	48	|		|

dx			= how many steps between the tho values of x
dy			= how many steps between the tho values of y
2dy			= 
P0 			= 2dy - dx
P0 			= ??????????????????????????????






1. aX < bX		&&		0 <= m <= 1
2. aY < bY		&&		1 < m < infinity
3. aY < bY		&&		-1 > m > -infinity
4. bX < aX		&&		0 >= m >= -1
5. bX < aX		&&		0 < m <= 1
6. bY < aY		&&		1 < m < infinity
7. bY < aY		&&		-1 > m > -infinity
8. aX < bX		&&		0 >= m >= -1

Octant 1: 		Do Nothing

Octant 2: 		swap aX, aY
				swap bX, bY
				put_pixel(Y,X)

Octant 3: 		swap aX, aY
				swap bX, bY
				Y *= -1
				put_pixel(Y,X)

Octant 4: 		X *= -1
				put_pixel(X,Y)

Octant 5: 		Y *= -1
				X *= -1
				put_pixel(X,Y)

Octant 6: 		swap aX, aY
				swap bX, bY
				Y *= -1
				X *=* -1
				put_pixel(Y,X)

Octant 7: 		swap aX, aY
				swap bX, bY
				X *= -1
				put_pixel(Y,X)

Octant 8: 		Y *= -1
				put_pixel(X,Y)