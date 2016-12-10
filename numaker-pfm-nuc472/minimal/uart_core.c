#include <unistd.h>
#include "py/mpconfig.h"
#include "NUC472_442.h"
#include "uart.h"

/*
 * Core UART functions to implement for a port
 */

#if MICROPY_MIN_USE_STM32_MCU
#endif

// Receive single character
int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
#if MICROPY_MIN_USE_STDOUT
    int r = read(0, &c, 1);
    (void)r;
#elif MICROPY_MIN_USE_STM32_MCU
    // wait for RXNE
    while ((UART3->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk)) {
    }
    c = UART_READ(UART3);
#endif
    return c;
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
#if MICROPY_MIN_USE_STDOUT
    int r = write(1, str, len);
    (void)r;
#elif MICROPY_MIN_USE_STM32_MCU
    while (len--) {
        // wait for TXE
        while(!(((UART3->FIFOSTS) & UART_FIFOSTS_TXEMPTYF_Msk) >> UART_FIFOSTS_TXEMPTYF_Pos));

        UART_WRITE(UART3,*str++);
    }
#endif
}
