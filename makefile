out/sim: out/main.o out/engine.o out/cluster.o out/glad.o out/display.o out/circle.o out/mesh.o
	g++ out/main.o out/engine.o out/cluster.o out/glad.o out/display.o out/circle.o out/mesh.o -o out/sim -lglfw 

out/main.o: src/main.cpp src/display.cpp 
	g++ -c src/main.cpp -o out/main.o -Iinc -lglfw -lGL

out/engine.o: src/engine.cpp
	g++ -c src/engine.cpp -o out/engine.o 

out/cluster.o: src/cluster.cpp
	g++ -c src/cluster.cpp -o out/cluster.o -Iinc

out/display.o: src/display.cpp
	g++ -c src/display.cpp -o out/display.o -Iinc -lglfw -lGL

out/circle.o: src/circle.cpp
	g++ -c src/circle.cpp -o out/circle.o -Iinc -lgflw -lGL

out/mesh.o: src/mesh.cpp
	g++ -c src/mesh.cpp -o out/mesh.o -Iinc

out/glad.o: src/glad.c 
	gcc -c src/glad.c -o out/glad.o -Iinc

clean:
	rm -r out/*
