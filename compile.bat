g++ -O3 -march=native -I./src -c ./src/main.cpp -o ./obj/main.obj

g++ ./obj/main.obj -L./lib -lsfml-system -o ./bin/program.exe 