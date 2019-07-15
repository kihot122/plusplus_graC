mkdir obj
mkdir obj\cell
mkdir obj\virtual

g++ -O3 -march=native -I./src -c ./src/client.cpp -o ./obj/client.obj
g++ -O3 -march=native -I./src -c ./src/server.cpp -o ./obj/server.obj
g++ -O3 -march=native -I./src -c ./src/window.cpp -o ./obj/window.obj
g++ -O3 -march=native -I./src -c ./src/cell/cell.cpp -o ./obj/cell/cell.obj
g++ -O3 -march=native -I./src -c ./src/cell/map.cpp -o ./obj/cell/map.obj
g++ -O3 -march=native -I./src -c ./src/virtual/snake.cpp -o ./obj/virtual/snake.obj

g++ ./obj/window.obj ./obj/cell/cell.obj ./obj/cell/map.obj ./obj/virtual/snake.obj ./obj/client.obj -L./lib -o ./bin/client.exe -lsfml-graphics -lsfml-window -lsfml-system

g++ ./obj/cell/cell.obj ./obj/cell/map.obj ./obj/virtual/snake.obj ./obj/server.obj -L./lib -o ./bin/server.exe 