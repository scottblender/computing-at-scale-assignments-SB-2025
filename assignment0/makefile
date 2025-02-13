read-matrix-market.o : read-matrix-market.cpp
	g++ -c read-matrix-market.cpp

write-matrix-market.o : write-matrix-market.cpp
	g++ -c write-matrix-market.cpp

matrix-vector-product.o : matrix-vector-product.cpp
	g++ -c matrix-vector-product.cpp

matrix-matrix-product.o : matrix-matrix-product.cpp
	g++ -c matrix-matrix-product.cpp

mmio.o : mmio.c
	g++ -c mmio.c
         
main-script.o : main-script.cpp
	g++ -c main-script.cpp

main : main-script.o mmio.o matrix-matrix-product.o matrix-vector-product.o write-matrix-market.o read-matrix-market.o 
	g++ main-script.o mmio.o matrix-matrix-product.o matrix-vector-product.o write-matrix-market.o read-matrix-market.o -o main

       
