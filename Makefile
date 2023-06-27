all:
	rm -f localize
	rm -f *.o
	rm -f codegen/exe/localize/*.o
	make -f matlab-coder-utils/Makefile PRODUCT_NAME=localize -j4
