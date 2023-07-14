echo "Start compiler"
cd src
g++ -std=c++20 -o run_file_compile main.cpp
echo "Run:"
echo "cd src"
echo "./floyzcpp <args>"
echo "<args> = create"