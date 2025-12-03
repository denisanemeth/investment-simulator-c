all:
	gcc src/investment_sim.c src/investment_func.c -lm -o investment_sim

run:
	./investment_sim

clean:
	rm -f investment_sim
