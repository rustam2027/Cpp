docker cp matrix_test.cpp practical_hawking:/var/usr/Documents/Github/cpp
docker cp matrix.cpp practical_hawking:/var/usr/Documents/Github/cpp

docker exec practical_hawking clang++ matrix_test.cpp
docker exec practical_hawking valgrind --leak-check=full -s ./a.out
docekr exec practical_hawkind em a.out

# clang++ -std=c++17 matrix_test.cpp -fsanitize=undefined -fsanitize=address
# ./a.out
# rm a.out
