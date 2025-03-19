/*
 * main.c
 *
 *  Created on: Mar 19, 2025
 *      Author: Mariem
 */

#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../HAL/LCD_int.h"
#include"util/delay.h"
#include <stdlib.h>

typedef struct {
    u8 x;
    u8 y;
} SN_pos;

SN_pos snake[4] = { {3,0}, {2,0}, {1,0}, {0,0} };
SN_pos Food_Pos;
u8 Score = 0;
// col activation array
char a[] = {1, 2, 4, 8, 16, 32, 64, 128};

u8 snakeData[8] = {0};
u8 foodData[8] = {0};
void Moving_Right();
void Moving_Left();
void Moving_Up();
void Moving_Down();
void UpdateSnakeData();
void GenerateFood();
void display();
void displayPattern(u8 pattern[8]);

void displayPattern(u8 pattern[8]) {
    for (int refresh = 0; refresh < 30; refresh++) { // refresh to create a stable image
        for (int i = 0; i < 8; i++) {
            enuSetPortValue(DIO_PORTD, ~a[i]);
            enuSetPortValue(DIO_PORTC, pattern[i]);
            _delay_ms(2);
        }
    }
}


void UpdateSnakeData() {
    for (u8 i = 0; i < 8; i++)
        snakeData[i] = 0x00;

    for (u8 i = 0; i < 4; i++) {
        u8 x = snake[i].x;
        u8 y = snake[i].y;
        snakeData[y] |= (1 << x);
    }
}


void GenerateFood() {
    u8 valid_position = 0;

    while (!valid_position) {
        Food_Pos.x = rand() % 8;
        Food_Pos.y = rand() % 8;
        valid_position = 1;
        for (u8 i = 0; i < 4; i++) {
            if (Food_Pos.x == snake[i].x && Food_Pos.y == snake[i].y) {
                valid_position = 0;
                break;
            }
        }
    }

    for (u8 i = 0; i < 8; i++)
        foodData[i] = 0x00;

    foodData[Food_Pos.y] |= (1 << Food_Pos.x);
}

void display() {
    u8 combinedData[8];

    for (u8 i = 0; i < 8; i++)
        combinedData[i] = snakeData[i] | foodData[i];

    displayPattern(combinedData);
}

void Moving_Right() {
    for(int i = 3; i > 0; i--)
        snake[i] = snake[i-1];
    snake[0].x++;
}

void Moving_Left() {
    for(int i = 3; i > 0; i--)
        snake[i] = snake[i-1];
    snake[0].x--;
}

void Moving_Up() {
    for(int i = 3; i > 0; i--)
        snake[i] = snake[i-1];
    snake[0].y--;
}

void Moving_Down() {
    for(int i = 3; i > 0; i--)
        snake[i] = snake[i-1];
    snake[0].y++;
}

int main(void) {

    enuSetPortDirection(DIO_PORTD, 0xFF);
    enuSetPortDirection(DIO_PORTC, 0xFF);
    enuSetPortValue(DIO_PORTD, 0xFF);
    enuSetPortValue(DIO_PORTC, 0x00);

    enuSetPinDirection(DIO_PORTA, DIO_PIN3, INPUT);
    enuSetPinDirection(DIO_PORTA, DIO_PIN4, INPUT);
    enuSetPinDirection(DIO_PORTA, DIO_PIN5, INPUT);
    enuSetPinDirection(DIO_PORTA, DIO_PIN6, INPUT);

    enuSetPortValue(DIO_PORTA, 0xFF);

    LCD_enuInit();

    unsigned char data0[] = "Welcome";
    unsigned char data1[] = "to SnakeGame ~~~~:-";

    int i = 0, x;
    while(data0[i] != '\0') {
        LCD_enuDisplayChar(data0[i]);
        _delay_ms(100);
        i++;
    }

    LCD_enuSendCommand(0xC0);
    i = 0;
    while(data1[i] != '\0') {
        LCD_enuDisplayChar(data1[i]);
        _delay_ms(100);
        i++;
    }

    for(x = 0; x < 16; x++) {
        LCD_enuSendCommand(0x1c);
        _delay_ms(100);
    }

    displayPattern(snakeData);
    LCD_enuSendCommand(0x01);
    LCD_enuSendString("Score:");

    GenerateFood();
    display();

    u8 PIN3, PIN4, PIN5, PIN6;

    while(1) {

        enuGetPinValue(DIO_PORTA, DIO_PIN3, &PIN3);
        enuGetPinValue(DIO_PORTA, DIO_PIN4, &PIN4);
        enuGetPinValue(DIO_PORTA, DIO_PIN5, &PIN5);
        enuGetPinValue(DIO_PORTA, DIO_PIN6, &PIN6);

        if(PIN3 == 0) Moving_Up();
        else if(PIN4 == 0) Moving_Left();
        else if(PIN5 == 0) Moving_Right();
        else if(PIN6 == 0) Moving_Down();

        UpdateSnakeData();
        if (Food_Pos.x == snake[0].x && Food_Pos.y == snake[0].y) {
            Score++;
            LCD_enuSetPosition(7,0);
            LCD_enuDisplayChar(Score+'0');
            GenerateFood();
            _delay_ms(500);
        }

        display();
        _delay_ms(50);
    }
}
