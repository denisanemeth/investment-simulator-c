#!/bin/bash
echo "=== Test 1: Fără contribuții lunare ==="
./investment_sim --initial 10000 --rate 0.07 --years 20

echo -e "\n=== Test 2: Doar contribuții lunare ==="
./investment_sim --initial 0 --monthly 500 --rate 0.05 --years 10

echo -e "\n=== Test 3: Fără dobândă ==="
./investment_sim --initial 5000 --monthly 100 --rate 0 --years 5

echo -e "\n=== Test 4: Inflație mare ==="
./investment_sim --initial 10000 --rate 0.05 --inflation 0.08 --years 15

echo -e "\n=== Test 5: Valori mari ==="
./investment_sim --initial 1000000 --monthly 10000 --rate 0.08 --years 30

echo -e "\n=== Test 6: Comparare rate ==="
./investment_sim --compare "0.03,0.05,0.07,0.10" --initial 10000 --years 20

echo -e "\n=== Test 7: Monte Carlo ==="
./investment_sim --scenarios 500 --rate_range "0.03-0.09" --initial 10000 --years 15

echo -e "\n=== Test 8: Export & Chart ==="
./investment_sim --initial 5000 --monthly 200 --rate 0.06 --years 10 --chart --export test_results.csv

echo -e "\n=== Toate testele completate! ==="