install tools for compiling:
sudo apt-get install g++ freeglut3 freeglut3-dev

compile:
g++ homer.cpp -o homer -lGL -lGLU -lglut

launch:
./homer