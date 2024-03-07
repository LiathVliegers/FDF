Great sources:

miniLibX:
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

MLX42:
https://github.com/codam-coding-college/MLX42/blob/master/README.md


good github page:
https://github.com/ailopez-o/42Barcelona-FdF/blob/main/README.md




map:

0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8 9
0 0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 0 1 2 3 4 5 6 9
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1

width = 11
max width = 12
index = -1

pointer to z_value :
index:	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11|
value:	|   |   |   |   |   |   |   |   |   |   |   |   |

line:
index:	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11|
value:	| 0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | ? |

split_line:
index	value
0		0
1		0
2		1
3		2
4		3
5		4
6		5
7		6
8		7
9		8
10		9
11		NULL




split_line:
index	value
0		0
1		0
2		1,0x810202
3		2
4		3
5		4
6		5
7		6
8		7
9		8
10		9
11		NULL



split_line:
index	value
0		1
1		0x810202
2		NULL




r = 81
g = 02
b = 02
a = FF
0x810202FF

r << 24 | g << 16 | b << 8 | a;



structs dereferencing   (:S)
(*map).height			= map->height
(*(points_row + i)).z	= points_row[i].z