prog:	main.o prototypes1.o
	g++ -o rorders main.o prototypes1.o

main.o:	main.cpp prototypes1.h
	g++ -c main.cpp

prototypes1.o: prototypes1.cpp prototypes1.h
	g++ -c prototypes1.cpp

clean:	
	rm *.o

