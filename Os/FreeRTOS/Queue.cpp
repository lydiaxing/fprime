#include <FreeRTOS/Queue.hpp>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "FreeRTOS.h"
#include "queue.h"
#include <iostream>
using namespace std;

// THIS SUCKS PLACE IT SOMEWHERE ELSE
const int QUEUE_BLOCK_DURATION = 1000;

namespace Os {

    Queue::Queue() :
        m_handle(-1) {
    }

    Queue::QueueStatus Queue::create(const Fw::StringBase &name, NATIVE_INT_TYPE depth, NATIVE_INT_TYPE msgSize)
    {

        this->m_name = "/QP_";
        this->m_name += name;

        QueueHandle_t queueHandle;
        queueHandle = xQueueCreate(depth, msgSize);

        if (NULL == queueHandle) {
          return QUEUE_UNINITIALIZED;
        }
        this->m_handle = (POINTER_CAST) queueHandle;
        this->depth = depth;
        this->msgSize = msgSize;

        Queue::s_numQueues++;

        return QUEUE_OK;
    }

    Queue::~Queue() {
        if (this->m_handle != NULL)
        {
            vQueueDelete((QueueHandle_t) this->m_handle);
        }
    }


    Queue::QueueStatus Queue::send(const U8* buffer, NATIVE_INT_TYPE size, NATIVE_INT_TYPE priority, QueueBlocking block)
    {
        QueueHandle_t queueHandle = (QueueHandle_t) this->m_handle;

        if (NULL == queueHandle)
        {
          return QUEUE_UNINITIALIZED;
        }
        if (NULL == buffer)
        {
          return QUEUE_EMPTY_BUFFER;
        }

        // if (size != getMsgSize()) return QUEUE_SIZE_MISMATCH;

        if (block == QUEUE_NONBLOCKING)
        {
            if (xQueueSendToBack(queueHandle, (void*) buffer, (TickType_t)0) == errQUEUE_FULL)
            {
                return QUEUE_FULL;
            }
        }
        else
        {
            if (xQueueSendToBack(queueHandle, (void*) buffer, (TickType_t)QUEUE_BLOCK_DURATION) != pdPASS)
            {
                return QUEUE_UNKNOWN_ERROR;
            }
        }

        return QUEUE_OK;
    }


    Queue::QueueStatus Queue::receive(U8* buffer, NATIVE_INT_TYPE capacity, NATIVE_INT_TYPE &actualSize, NATIVE_INT_TYPE &priority, QueueBlocking block)
    {
        QueueHandle_t queueHandle = (QueueHandle_t) this->m_handle;

        if (NULL == queueHandle)
        {
            return QUEUE_UNINITIALIZED;
        }

        if (NULL == buffer)
        {
            return QUEUE_EMPTY_BUFFER;
        }

        // if (size != getMsgSize()) return QUEUE_SIZE_MISMATCH;

        if (block == QUEUE_NONBLOCKING)
        {
            if (xQueueReceive(queueHandle, (void*) buffer, (TickType_t) 0) == errQUEUE_EMPTY)
            {
                return QUEUE_NO_MORE_MSGS;
            }
        }
        else
        {
            if (xQueueReceive(queueHandle, (void*) buffer, (TickType_t) QUEUE_BLOCK_DURATION) == errQUEUE_EMPTY)
            {
                return QUEUE_NO_MORE_MSGS;
            }
        }

        actualSize = (NATIVE_INT_TYPE) this->getMsgSize();

        return QUEUE_OK;
    }

    /**************************************************************
     *   WE NEED TO EDIT QUEUE.HPP FOR THE STUFF BELOW TO WORK    *
     **************************************************************/

    NATIVE_INT_TYPE Queue::getNumMsgs(void) const
    {
        return uxQueueMessagesWaiting((QueueHandle_t) this->m_handle);
    }

    NATIVE_INT_TYPE Queue::getMaxMsgs(void) const
    {
        // FW_ASSERT(0);
        return 0;
    }

    NATIVE_INT_TYPE Queue::getQueueSize(void) const
    {
        return this->depth;
    }

    NATIVE_INT_TYPE Queue::getMsgSize(void) const
    {
        return this->msgSize;
    }

}

