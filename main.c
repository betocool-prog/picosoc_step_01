/*
 *  PicoSoC - A simple example SoC using PicoRV32
 *
 *  Copyright (C) 2017  Clifford Wolf <clifford@clifford.at>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include <stdint.h>
#include <stdbool.h>

#define reg_leds (*(volatile uint32_t*)0x03000000)

// --------------------------------------------------------

/* Private functions */
static void led_counter(void);

#define LED_DELAY   162338  // Equivalent to 0.125 secs
static uint32_t delay = LED_DELAY;

void main()
{
	reg_leds = 0x0;

	while (1)
	{
		led_counter();
	}
}

static void led_counter(void)
{

    delay--;

    if(delay == 0)
    {
        delay = LED_DELAY;
        
        reg_leds = reg_leds + 1;
        if (reg_leds == 0x10)
        {
            reg_leds = 0;
        }
    }
}