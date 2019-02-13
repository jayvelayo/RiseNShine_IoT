
#include <stdio.h>

#include "esp_system.h"

#include "connect_to_wifi.h"
#include "TCP_server.h"
#include "clock_management.h"

#include "esp_log.h"
#include "nvs_flash.h" // for nvs_flash_init()

void app_main()
{
    ESP_ERROR_CHECK( nvs_flash_init() );
    initialise_wifi();
    wait_for_ip();
    xTaskCreate(vTaskClockSystem, "clock_management_task", 2048, NULL, 10, NULL);
    xTaskCreate(tcp_server_task, "tcp_server", 4096, NULL, 5, NULL);
}