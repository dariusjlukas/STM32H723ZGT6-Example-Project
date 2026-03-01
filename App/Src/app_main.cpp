/* SPDX-License-Identifier: MIT */

#include "app_main.h"
#include "main.h"
#include "usbd_cdc_if.h"

extern "C" void app_init(void)
{
}

extern "C" void app_loop(void)
{
    const char buf[] = {"LED Toggled\r\n"};
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    CDC_Transmit_HS((uint8_t*)buf, strlen(buf));
    HAL_Delay(1000);
}
