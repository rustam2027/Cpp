docker cp ScopedPointer.cpp practical_hawking:/var/usr/Documents/Github/cpp
docker exec practical_hawking clang++ ScopedPointer.cpp
docker exec practical_hawking valgrind ./a.out
