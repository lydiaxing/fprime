#include <Os/Mutex.hpp>
#include <Fw/Types/Assert.hpp>
#include <stdio.h>
#include <iostream>
#include "FreeRTOS.h"
#include "semphr.h"

namespace Os {

   /*Mutex::Mutex(void) {
        pthread_mutex_t* handle = new pthread_mutex_t;
        NATIVE_INT_TYPE stat = pthread_mutex_init(handle,0);
        FW_ASSERT(stat == 0,stat);
        this->m_handle = (POINTER_CAST) handle;
    }*/

    Mutex::Mutex(void) {
        SemaphoreHandle_t xSemaphore;
        xSemaphore = xSemaphoreCreateMutex();
        if (xSemaphore == NULL){
            puts("Failed to create mutex.");
        }
        this->m_handle = (POINTER_CAST) xSemaphore;
    }

    Mutex::~Mutex(void) {
        if (this->m_handle != NULL){
          vSemaphoreDelete((SemaphoreHandle_t) this->m_handle);
        }
        else{
          puts("MutexHandle hasn't been created.");
        }
    }

    /*void Mutex::lock(void) {
        NATIVE_INT_TYPE stat = pthread_mutex_lock((pthread_mutex_t*)this->m_handle);
        FW_ASSERT(stat == 0,stat);
    }

    void Mutex::unLock(void) {
        NATIVE_INT_TYPE stat = pthread_mutex_unlock((pthread_mutex_t*)this->m_handle);
        FW_ASSERT(stat == 0,stat);
    }*/
    void Mutex::lock(void) {
        SemaphoreHandle_t xSemaphore = (SemaphoreHandle_t) this->m_handle;
        if (xSemaphore != NULL){
            if (xSemaphoreTake(xSemaphore, 1000) != pdPASS) {
                puts("Failed to get access within 1s.");
            }
            else {
                puts("Lock successfully.");
            }
        }
        else {
            puts("MutexHandle hasn't been created.");
        }
    }

    void Mutex::unLock(void) {
        SemaphoreHandle_t xSemaphore = (SemaphoreHandle_t) this->m_handle;
        if (xSemaphore != NULL) {
            if (xSemaphoreGive(xSemaphore) != pdPASS) {
                puts("Failed because the calling task is not the mutex holder.");
            }
            else {
                puts("Unlock successfully.");
            }
        }
        else {
            puts("MutexHandle hasn't been created.");
        }
    }

}

