/* SPDX-License-Identifier: MIT */

#include "app_main.h"
#include "main.h"
#include "usbd_cdc_if.h"

const char led_on[] = {"LED On\r\n"};
const char led_off[] = {"LED Off\r\n"};

extern "C" void app_init(void)
{
}

extern "C" void app_loop(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    CDC_Transmit_HS((uint8_t*)led_on, strlen(led_on));
    HAL_Delay(1000);

    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    CDC_Transmit_HS((uint8_t*)led_off, strlen(led_off));
    HAL_Delay(1000);
}
