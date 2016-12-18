//*****************************************************************************
//
// Startup code for use with GNU tools.
//
//*****************************************************************************


//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
static void Reset_Handler(void);
static void Default_Handler(void);

//*****************************************************************************
//
// External declaration for the interrupt handler used by the application.
//
//*****************************************************************************
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void BOD_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void IRC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void PWRWU_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void SRAMF_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void CLKF_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TAMPER_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void EINT0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT4_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT5_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT6_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EINT7_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void GPA_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPB_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPD_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPE_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPF_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPG_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPH_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void GPI_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TMR0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TMR1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TMR2_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TMR3_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void PDMA_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void WDT_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void WWDT_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EADC0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EADC1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EADC2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EADC3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void ACMP_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void OPA0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void OPA1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void ICAP0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void ICAP1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void PWM0CH0_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0CH1_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0CH2_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0CH3_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0CH4_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0CH5_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM0_BRK_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void QEI0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void PWM1CH0_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1CH1_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1CH2_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1CH3_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1CH4_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1CH5_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void PWM1_BRK_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void QEI1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void EPWM0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EPWM0BRK_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void EPWM1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void EPWM1BRK_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void USBD_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void USBH_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void USB_OTG_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void EMAC_TX_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void EMAC_RX_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void SPI0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void UART0_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void UART1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void UART2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void UART3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2C3_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2C4_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SC0_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SC1_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SC2_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SC3_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SC4_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SC5_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CAN0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void CAN1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2S0_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void I2S1_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void SD_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void PS2D_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void CAP_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CRYPTO_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void CRC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));

//*****************************************************************************
//
// The entry point for the application.
//
//*****************************************************************************
extern int main(void);

//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************
static unsigned long pulStack[512];

//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),
    // The initial stack pointer
    Reset_Handler,              // Reset Handler
    NMI_Handler,                // NMI Handler
    HardFault_Handler,          // Hard Fault Handler
    MemManage_Handler,          // MPU Fault Handler
    BusFault_Handler,           // Bus Fault Handler
    UsageFault_Handler,         // Usage Fault Handler
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    SVC_Handler,                // SVCall Handler
    DebugMon_Handler,           // Debug Monitor Handler
    0,                          // Reserved
    PendSV_Handler,             // PendSV Handler
    SysTick_Handler,            // SysTick Handler

    // External Interrupts
    BOD_IRQHandler,             // 0: Brown Out detection
    IRC_IRQHandler,             // 1: Internal RC
    PWRWU_IRQHandler,           // 2: Power Down Wake Up
    SRAMF_IRQHandler,           // 3: Reserved.
    CLKF_IRQHandler,            // 4: CLKF
    Default_Handler,            // 5: Reserved.
    RTC_IRQHandler,             // 6: Real Time Clock
    TAMPER_IRQHandler,          // 7: Tamper detection
    EINT0_IRQHandler,           // 8: External Input 0
    EINT1_IRQHandler,           // 9: External Input 1
    EINT2_IRQHandler,           // 10: External Input 2
    EINT3_IRQHandler,           // 11: External Input 3
    EINT4_IRQHandler,           // 12: External Input 4
    EINT5_IRQHandler,           // 13: External Input 5
    EINT6_IRQHandler,           // 14: External Input 6
    EINT7_IRQHandler,           // 15: External Input 7
    GPA_IRQHandler,             // 16: GPIO Port A
    GPB_IRQHandler,             // 17: GPIO Port B
    GPC_IRQHandler,             // 18: GPIO Port C
    GPD_IRQHandler,             // 19: GPIO Port D
    GPE_IRQHandler,             // 20: GPIO Port E
    GPF_IRQHandler,             // 21: GPIO Port F
    GPG_IRQHandler,             // 22: GPIO Port G
    GPH_IRQHandler,             // 23: GPIO Port H
    GPI_IRQHandler,             // 24: GPIO Port I
    Default_Handler,            // 25: Reserved.
    Default_Handler,            // 26: Reserved.
    Default_Handler,            // 27: Reserved.
    Default_Handler,            // 28: Reserved.
    Default_Handler,            // 29: Reserved.
    Default_Handler,            // 30: Reserved.
    Default_Handler,            // 31: Reserved.
    TMR0_IRQHandler,            // 32: Timer 0
    TMR1_IRQHandler,            // 33: Timer 1
    TMR2_IRQHandler,            // 34: Timer 2
    TMR3_IRQHandler,            // 35: Timer 3
    Default_Handler,            // 36: Reserved.
    Default_Handler,            // 37: Reserved.
    Default_Handler,            // 38: Reserved.
    Default_Handler,            // 39: Reserved.
    PDMA_IRQHandler,            // 40: Peripheral DMA
    Default_Handler,            // 41: Reserved.
    ADC_IRQHandler,             // 42: ADC
    Default_Handler,            // 43: Reserved.
    Default_Handler,            // 44: Reserved.
    Default_Handler,            // 45: Reserved.
    WDT_IRQHandler,             // 46: Watch Dog Timer
    WWDT_IRQHandler,            // 47: Window Watch Dog Timer
    EADC0_IRQHandler,           // 48: EDAC 0
    EADC1_IRQHandler,           // 49: EDAC 1
    EADC2_IRQHandler,           // 50: EDAC 2
    EADC3_IRQHandler,           // 51: EDAC 3
    Default_Handler,            // 52: Reserved.
    Default_Handler,            // 53: Reserved.
    Default_Handler,            // 54: Reserved.
    Default_Handler,            // 55: Reserved.
    ACMP_IRQHandler,            // 56: Analog Comparator
    Default_Handler,            // 57: Reserved.
    Default_Handler,            // 58: Reserved.
    Default_Handler,            // 59: Reserved.
    OPA0_IRQHandler,            // 60: OPA 0
    OPA1_IRQHandler,            // 61: OPA 1
    ICAP0_IRQHandler,           // 62: ICAP 0
    ICAP1_IRQHandler,           // 63: ICAP 1
    PWM0CH0_IRQHandler,         // 64: PWM0 CH0
    PWM0CH1_IRQHandler,         // 65: PWM0 CH1
    PWM0CH2_IRQHandler,         // 66: PWM0 CH2
    PWM0CH3_IRQHandler,         // 67: PWM0 CH3
    PWM0CH4_IRQHandler,         // 68: PWM0 CH4
    PWM0CH5_IRQHandler,         // 69: PWM0 CH5
    PWM0_BRK_IRQHandler,        // 70: PWM0 Break
    QEI0_IRQHandler,            // 71: QEI 0
    PWM1CH0_IRQHandler,         // 72: PWM1 CH0
    PWM1CH1_IRQHandler,         // 73: PWM1 CH1
    PWM1CH2_IRQHandler,         // 74: PWM1 CH2
    PWM1CH3_IRQHandler,         // 75: PWM1 CH3
    PWM1CH4_IRQHandler,         // 76: PWM1 CH4
    PWM1CH5_IRQHandler,         // 77: PWM1 CH5
    PWM1_BRK_IRQHandler,        // 78: PWM1 Break
    QEI1_IRQHandler,            // 79: QEI 1
    EPWM0_IRQHandler,           // 80: EPWM0
    EPWM0BRK_IRQHandler,        // 81: EPWM0 Break
    EPWM1_IRQHandler,           // 82: EPWM1
    EPWM1BRK_IRQHandler,        // 83: EPWM1 Break
    Default_Handler,            // 84: Reserved.
    Default_Handler,            // 85: Reserved.
    Default_Handler,            // 86: Reserved.
    Default_Handler,            // 87: Reserved.
    USBD_IRQHandler,            // 88: USB Device
    USBH_IRQHandler,            // 89: USB Host
    USB_OTG_IRQHandler,         // 90: USB OTG
    Default_Handler,            // 91: Reserved.
    EMAC_TX_IRQHandler,         // 92: Ethernet MAC TX
    EMAC_RX_IRQHandler,         // 93: Ethernet MAC RX
    Default_Handler,            // 94: Reserved.
    Default_Handler,            // 95: Reserved.
    SPI0_IRQHandler,            // 96: SPI 0
    SPI1_IRQHandler,            // 97: SPI 1
    SPI2_IRQHandler,            // 98: SPI 2
    SPI3_IRQHandler,            // 99: SPI 3
    Default_Handler,            // 100: Reserved.
    Default_Handler,            // 101: Reserved.
    Default_Handler,            // 102: Reserved.
    Default_Handler,            // 103: Reserved.
    UART0_IRQHandler,           // 104: UART 0
    UART1_IRQHandler,           // 105: UART 1
    UART2_IRQHandler,           // 106: UART 2
    UART3_IRQHandler,           // 107: UART 3
    UART4_IRQHandler,           // 108: UART 4
    UART5_IRQHandler,           // 109: UART 5
    Default_Handler,            // 110: Reserved.
    Default_Handler,            // 111: Reserved.
    I2C0_IRQHandler,            // 112: I2C 0
    I2C1_IRQHandler,            // 113: I2C 1
    I2C2_IRQHandler,            // 114: I2C 2
    I2C3_IRQHandler,            // 115: I2C 3
    I2C4_IRQHandler,            // 116: I2C 4
    Default_Handler,            // 117: Reserved.
    Default_Handler,            // 118: Reserved.
    Default_Handler,            // 119: Reserved.
    SC0_IRQHandler,             // 120: Smart Card 0
    SC1_IRQHandler,             // 121: Smart Card 1
    SC2_IRQHandler,             // 122: Smart Card 2
    SC3_IRQHandler,             // 123: Smart Card 3
    SC4_IRQHandler,             // 124: Smart Card 4
    SC5_IRQHandler,             // 125: Smart Card 5
    Default_Handler,            // 126: Reserved.
    Default_Handler,            // 127: Reserved.
    CAN0_IRQHandler,            // 128: CAN 0
    CAN1_IRQHandler,            // 129: CAN 1
    Default_Handler,            // 130: Reserved.
    Default_Handler,            // 131: Reserved.
    I2S0_IRQHandler,            // 132: I2S 0
    I2S1_IRQHandler,            // 133: I2S 1
    Default_Handler,            // 134: Reserved.
    Default_Handler,            // 135: Reserved.
    SD_IRQHandler,              // 136: SD card
    Default_Handler,            // 137: Reserved.
    PS2D_IRQHandler,            // 138: PS/2 device
    CAP_IRQHandler,             // 139: VIN
    CRYPTO_IRQHandler,          // 140: CRYPTO
    CRC_IRQHandler,             // 141: CRC
};

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where the
// the "data" and "bss" segments reside in memory.  The initializers for the
// for the "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************
extern unsigned long _etext;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;
extern void SystemInit();

//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.  Any fancy
// actions (such as making decisions based on the reset cause register, and
// resetting the bits in that register) are left solely in the hands of the
// application.
//
//*****************************************************************************
static void Reset_Handler(void)
{
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM.
    //
    pulSrc = &_etext;
    for(pulDest = &_sdata; pulDest < &_edata; )
    {
        *pulDest++ = *pulSrc++;
    }

    //
    // Zero fill the bss segment.
    //
    __asm("    ldr     r0, =_sbss\n"
          "    ldr     r1, =_ebss\n"
          "    mov     r2, #0\n"
          "    .thumb_func\n"
          "zero_loop:\n"
          "        cmp     r0, r1\n"
          "        it      lt\n"
          "        strlt   r2, [r0], #4\n"
          "        blt     zero_loop");

    // call system init.
	SystemInit();

    //
    // Call the application's entry point.
    //
    main();
    for (;;) {
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void Default_Handler(void)
{
    //
    // Go into an infinite loop.
    //
    while(1)
    {
    }
}
