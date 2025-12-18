# Investment Simulator - C Project

Investment simulation program with compound interest, monthly contributions and scenario analysis.

## Features

- Investment simulation with compound interest
- Optional monthly contributions
- Inflation adjustment (real vs nominal value)
- Scenarios: optimistic, realistic, pessimistic
- Comparison between multiple interest rates
- Monte Carlo simulation (random scenarios)
- ASCII chart and CSV export

## Compilation
```bash
make
```

## Usage

### Simple example
```bash
./investment_sim --initial 10000 --rate 0.07 --years 20
```

### Main parameters

- `--initial <amount>` - Initial amount (RON)
- `--monthly <amount>` - Monthly contribution
- `--rate <rate>` - Interest rate (e.g., 0.07 = 7%)
- `--inflation <rate>` - Inflation rate (default: 0.03)
- `--years <years>` - Investment period
- `--chart` - Display chart
- `--export <file.csv>` - Export results

### Examples

**With monthly contributions:**
```bash
./investment_sim --initial 5000 --monthly 500 --rate 0.06 --years 10
```

**Rate comparison:**
```bash
./investment_sim --compare "0.03,0.05,0.07,0.10" --initial 10000 --years 20
```

**Monte Carlo:**
```bash
./investment_sim --scenarios 500 --rate_range "0.03-0.09" --initial 10000 --years 15
```

**With chart and export:**
```bash
./investment_sim --initial 5000 --monthly 200 --rate 0.06 --years 10 --chart --export results.csv
```

## Project Structure
```
├── src/
│   ├── investment_func.c  # Function implementation
│   ├── investment_func.h  # Header file
│   └── investment_sim.c   # Main program
├── .gitattributes         # Git configuration
├── Dockerfile             # Docker container setup
├── Makefile               # Build configuration
├── README.md              # Documentation
└── script.sh              # Test script
```

## Tests
```bash
bash script.sh
```

## Main Functions

**Calculations:**
- `compound_interest()` - Compound interest
- `compound_with_contributions()` - With periodic contributions
- `compute_roi()` - Return on Investment
- `find_breakeven_years()` - Breakeven year

**Simulations:**
- `simulate_scenario()` - Complete simulation
- `compare_rates()` - Compare different rates
- `monte_carlo_simulation()` - Monte Carlo analysis

**Utilities:**
- `draw_chart()` - ASCII chart
- `export_to_csv()` - Data export

## Output

The program displays:
- Annual table with nominal and real value
- Interest earned each year
- ROI and breakeven point
- Optimistic/pessimistic scenarios

## Clean Up
```bash
make clean
```

---
## Docker Hub

The project is available as a Docker image on Docker Hub.

### Pull and run:
```bash
docker pull denisanemeth/investment-simulator:latest
docker run --rm denisanemeth/investment-simulator:latest --initial 10000 --rate 0.07 --years 20
```

**Docker Hub:** https://hub.docker.com/r/denisanemeth/investment-simulator

### Examples:
```bash
# With monthly contributions
docker run --rm denisanemeth/investment-simulator:latest --initial 5000 --monthly 500 --rate 0.06 --years 10

# Rate comparison
docker run --rm denisanemeth/investment-simulator:latest --compare "0.03,0.05,0.07,0.10" --initial 10000 --years 20

# Monte Carlo simulation
docker run --rm denisanemeth/investment-simulator:latest --scenarios 500 --rate_range "0.03-0.09" --initial 10000 --years 15
```

**Note:** Educational project.