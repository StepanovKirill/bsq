# bsq
final project from C Pool School 21
Search biggest square on map, avoid obstacle. If such square is several, print leftmost and topmost.

## usage:
1) With "$ perl map_generator x_size y_size density > map_name" generate map;
2) Compile bsq with make or gcc -Wall -Wextra -Werror *.c -o bsq;
3) Use with ./bsq (or bsq.exe for Windows): "$ ./bsq map_file" or "$ ./bsq < map_file"
4) Program print in stdout biggest square, avoid obstacle, or print "map error" in stderr;
