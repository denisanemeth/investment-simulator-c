all:
	gcc investment_sim.c -o investment_sim

run:
	./investment_sim

clean:
	rm -f investment_sim
