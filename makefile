out/sim: out/main.o out/engine.o out/cluster.o out/glad.o
	g++ out/main.o out/engine.o out/cluster.o out/glad.o -o out/sim -lglfw 

out/main.o: src/main.cpp src/render.hpp
	g++ -c src/main.cpp -o out/main.o -Iinc -lglfw -lGL

out/engine.o: src/engine.cpp
	g++ -c src/engine.cpp -o out/engine.o 

out/cluster.o: src/cluster.cpp
	g++ -c src/cluster.cpp -o out/cluster.o

out/glad.o: src/glad.c 
	gcc -c src/glad.c -o out/glad.o -Iinc

clean:
	rm -r out/*
