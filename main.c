#include "lib/include.h"

int main(void)
{

    uint16_t Result[2];
    uint16_t duty[2];
    Configurar_PLL();  //Confiuracion de velocidad de reloj
    Configura_Reg_ADC0();
    Configurar_UART0();
    Configura_Reg_PWM1(1000);//Configuro a 1khz el pwm
    while(1)
    {
        ADC0_InSeq2(Result,duty); //llamada a la conversion por procesador
        PWM0->_1_CMPB = duty[0];
        PWM0->_1_CMPA = duty[1];
        PWM0->_0_CMPA = 15000;
        
    }

}
