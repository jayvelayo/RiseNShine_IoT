/**
 * risenshine_systemtasks_tcpserver
 * 
 * Task implementation for the TCP Server
 */

#include "risenshine_systemtasks.h"

#include "TCP_server.h"

#include "esp_log.h"

const char * TAG = "TCP task";

static int charToInt(char * chars, int len)
{
    int x = 0;
    int i;
    for(i = 0; i < len; i++) 
    {
        if(chars[i] >= '0' && chars[i] <= '9')
        {
            x = x*10 + (chars[i]-'0');
        }
    }
    return x;
}

void processTCPCommand(char* dataBuffer, int len)
{
    int numSteps = charToInt(dataBuffer, len);
    ESP_LOGI(TAG, "Received number: %d", numSteps);
    xQueueSend(qStepperMotorSteps, &numSteps, 0);
}

void vTaskTCPServer(void *pvParameters)
{
    struct sockaddr_in my_addr;
    int socketfd;

    qStepperMotorSteps = xQueueCreate(2, sizeof(int));
    if(tcp_createAndBindSocket(&my_addr, &socketfd))
    {
        tcp_acceptClients(socketfd, &processTCPCommand);
    }
    else
    {
        vTaskDelete(NULL);
        /* code */
    }
    
    
}