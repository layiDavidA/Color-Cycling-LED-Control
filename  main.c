/* Name: Olayiwola David Abraham
 * Date: 2/7/24
Color Cycling LED Control

/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

    volatile uint32_t i;

void RGB_output(uint8_t count){
    // Function to output to RGB LED based on count value between 0 and 7'
    switch(count){

           case 0:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           for(i = 300000; i > 0; i--);
           break;

           case 1:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0); //red
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 2:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);//green
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 3:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN1 |GPIO_PIN0);//yellow
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 4:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);//blue
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 5:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN2 |GPIO_PIN0);//magenta
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 6:
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2 |GPIO_PIN1);//cyan
           for(i = 300000; i > 0; i--);
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           break;

           case 7:
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
            for(i = 300000; i > 0; i--);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
            break;
           }

}

//![Simple GPIO Config]
int main(void)
 {
    volatile uint32_t i;
    uint8_t count = 0;
    uint8_t flag = 0;

    /* stop Watchdog timer */
    WDT_A_hold(WDT_A_BASE);

    /* Configuring P1.0 as output */
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2);

    while (1)
    {
        RGB_output(count);

        if(count == 7 ){
            flag = 1;
        }
        else if(count == 0 ){
            flag = 0;
        }
        if(flag ==0){
            count++;
        }
        else if(flag==1){
        count--;
        }

        }
    }
