mkdir obj
mkdir obj\cell
mkdir obj\virtual

g++ -O3 -march=native -I./src -c ./src/client.cpp -o ./obj/client.obj
g++ -O3 -march=native -I./src -c ./src/server.cpp -o ./obj/server.obj
g++ -O3 -march=native -I./src -c ./src/window.cpp -o ./obj/window.obj
g++ -O3 -march=native -I./src -c ./src/cell/cell.cpp -o ./obj/cell/cell.obj
g++ -O3 -march=native -I./src -c ./src/virtual/snake.cpp -o ./obj/virtual/snake.obj

g++ ./obj/client.obj ./obj/window.obj ./obj/cell/cell.obj ./obj/virtual/snake.obj -L./lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o ./bin/client.exe 

g++ ./obj/server.obj ./obj/cell/cell.obj ./obj/virtual/snake.obj -L./lib -o ./bin/server.exe