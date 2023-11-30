#ifndef _KPD_CONFIG_H
#define _KPD_CONFIG_H
/*
    OPTION:
        *PORTA
        *PORTB
        *PORTC
        *PORTD
*/


#define KPD_COLS_PORT   PORTC
#define KPD_ROWS_PORT   PORTC


#define KPD_R0_PIN   PIN0
#define KPD_R1_PIN   PIN1
#define KPD_R2_PIN   PIN2
#define KPD_R3_PIN   PIN3
#define KPD_C0_PIN   PIN4
#define KPD_C1_PIN   PIN5
#define KPD_C2_PIN   PIN6
#define KPD_C3_PIN   PIN7

#define KPD_VAL      {\
                        {7, 8, 9, '/'},\
                        {4, 5, 6,'*'},\
                        {1, 2, 3,'-'},\
                        {'O',0,'C','+'},\
                     }

#define KPD_NUM_OF_COLS 4
#define KPD_NUM_OF_ROWS 4

#define KPD_DEFAULT_VAL 255






#endif
