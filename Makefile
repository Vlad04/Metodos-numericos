all:
	g++ -std=c++11 main.cpp -o main

run:
	./main
	Rscript plot.R
clean:
	rm -rf main
	rm -rf *.jpg
	rm -rf *Rout

