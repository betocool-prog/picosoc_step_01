#include <stdlib.h>
#include "Varty.h"
#include "verilated.h"
#include <verilated_vcd_c.h>

// Create an instance of our module under test

#define CLK_PERIOD	10.0f // Clock period in ns
#define MAX_SIM_TIME 0.001f * 1e9 // Simulation time

int main(int argc, char **argv)
{
	// Initialize Verilators variables
    Verilated::traceEverOn(true);
    double m_timestamp = 0;
	Varty *tb = new Varty;

    VerilatedVcdC *m_trace = new VerilatedVcdC;
    tb->trace(m_trace, 99);
    m_trace->open("waveform.vcd");

    while (m_timestamp < MAX_SIM_TIME)
	{
		tb->top__02Eclk ^= 1;
		tb->eval();
		m_trace->dump(m_timestamp);
		m_timestamp += CLK_PERIOD / 2;
	}

    m_trace->close();
    delete tb;
	exit(EXIT_SUCCESS);
}