#include <stdio.h>
#include "uart_console.h"

const char *TAG = "BOOT";

void uart_console_init(void)
{
    ESP_LOGI(TAG," UART, console init");
}
