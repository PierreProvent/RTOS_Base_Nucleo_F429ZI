#include "mbed.h"

Serial pc(USBTX,USBRX) ;

Thread thread1; // instanciation du thread 1
DigitalOut led1(LED1);

void led1_thread()
{
    while (true) {
        led1 = !led1;
        Thread::wait(100) ;
    }
}

int main (void)
{
    pc.printf("\033[2J"); // Effacement de la console
    pc.printf("\033[0;0H"); // Curseur en 0 ; 0
    pc.printf("Test de la carte Nucleo F429ZI sous RTOS MBED\n");
    pc.printf("Frequence de l'horloge systeme = %.2f MHz\n",SystemCoreClock/1000000.f) ;
    thread1.start(led1_thread);
    while(1) {
    }
}