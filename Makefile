LIBS = -lGL -lGLU -lglut

cubes : cubes.c
	gcc cubes.c -lGL -lGLU -lglut -std=c99