@.CHARSET CP1251
@ GNU AS

@.desc type=module
@ +------------------------------------------------------------------+
@ |      SET - ��������� ������������ GPIO ��������� RCC_AHB1ENR     |
@ +------------------------------------------------------------------+
@ | ������ ��������� ������������ ������������ � AHB1ENR GPIO A-I    |
@ |                                                                  |
@ | ��������!                                                        |
@ | ���������� ������ ���������� �������� RCC_AHB1ENR !              |
@ |                                                                  |
@ | ��� ������������� �������� � ����������� ������:                 |
@ |     .include "��� ����� ������"                                  |
@ |                                                                  |
@ | ��� ������ ������ ���������� �������� ���������:                 |
@ |    R0, R1                                                        |
@ | ���� � ���������� ��������� ������ �������� - ���������   ��  �� |
@ | ����� �� ��������� .include � ������������ �������� �����        |
@ |                                                                  |
@ +------------------------------------------------------------------+
@.enddesc

.equ  GPIOA_EN        , DISABLE  *  RCC_AHB1ENR_GPIOAEN  @ ������������ GPIO_A
.equ  GPIOB_EN        , DISABLE  *  RCC_AHB1ENR_GPIOBEN  @ ������������ GPIO_B
.equ  GPIOC_EN        , DISABLE  *  RCC_AHB1ENR_GPIOCEN  @ ������������ GPIO_C
.equ  GPIOD_EN        , DISABLE  *  RCC_AHB1ENR_GPIODEN  @ ������������ GPIO_D
.equ  GPIOE_EN        , DISABLE  *  RCC_AHB1ENR_GPIOEEN  @ ������������ GPIO_E
.equ  GPIOF_EN        , DISABLE  *  RCC_AHB1ENR_GPIOFEN  @ ������������ GPIO_F
.equ  GPIOG_EN        , DISABLE  *  RCC_AHB1ENR_GPIOGEN  @ ������������ GPIO_G
.equ  GPIOH_EN        , DISABLE  *  RCC_AHB1ENR_GPIOHEN  @ ������������ GPIO_H
.equ  GPIOI_EN        , DISABLE  *  RCC_AHB1ENR_GPIOIEN  @ ������������ GPIO_I

@ --------------------------  ������ �������� ��� ----------------------
@.item SWITCH
.equ  ENABLE          , 1 @ ��������
.equ  DISABLE         , 0 @ ���������
@.end

@.config GPIOA_EN=SWITCH GPIOB_EN=SWITCH GPIOC_EN=SWITCH GPIOD_EN=SWITCH GPIOE_EN=SWITCH GPIOF_EN=SWITCH GPIOG_EN=SWITCH GPIOH_EN=SWITCH GPIOI_EN=SWITCH
.include         "/src/inc/rcc.inc"

.equ  ahb1enr_v2    , GPIOA_EN+GPIOB_EN+GPIOC_EN+GPIOD_EN+GPIOE_EN+GPIOF_EN+GPIOG_EN+GPIOH_EN+GPIOI_EN

                LDR     R0, =PERIPH_BASE +  RCC_BASE + RCC_AHB1ENR
                LDR     R1, [R0]
                BFC     R1, 0, 9
                ADD     R1, ahb1enr_v2
                STR     R1, [R0]


