/** @file Task.cpp
 *  @brief Task implementation in FreeRTOS.
 *
 *  This contains the Task structure implementation in FreeRTOS.
 *
 *  @author Lydia Xing (lydiaxing)
 *  @author Jae Choi (Absolute0K)
 *  @bug No known bugs.
 */

#include <Os/Task.hpp>
#include <Fw/Types/Assert.hpp>

#include <string.h>
#include <time.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

namespace Os {
    Task::Task() : m_handle(0), m_identifier(0), m_affinity(-1), m_started(false), m_suspendedOnPurpose(false)
    {
    }

    Task::TaskStatus Task::start(const Fw::StringBase &name, NATIVE_INT_TYPE identifier, NATIVE_INT_TYPE priority, NATIVE_INT_TYPE stackSize, taskRoutine routine, void* arg, NATIVE_INT_TYPE cpuAffinity)
    {
        this->m_name = "TP_";
        this->m_name += name;
        this->m_identifier = identifier;

        Task::TaskStatus tStat = TASK_OK;
      	TaskHandle_t tid = (TaskHandle_t) this->m_handle;

      	BaseType_t stat = xTaskCreate(routine, this->m_name.toChar(), stackSize, arg, priority, &tid);

        // If a registry has been registered, register task
        if (Task::s_taskRegistry) {
            Task::s_taskRegistry->addTask(this);
        }

        switch (stat) {
            case pdPASS:
                Task::s_numTasks++;
                break;
            case errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY:
                // delete tid; //TODO: delete the handler
                tStat = TASK_INVALID_PARAMS;
                break;
            default:
                // delete tid;
                tStat = TASK_UNKNOWN_ERROR;
                break;
        }


        return tStat;
    }

    Task::TaskStatus Task::delay(NATIVE_UINT_TYPE milliseconds)
    {
        TickType_t xLastWakeTime = xTaskGetTickCount();

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(milliseconds));

        //TODO: add return TASK_DELAY_ERROR
        return TASK_OK; // for coverage analysis

    }


    Task::~Task()
    {
        // If a registry has been registered, remove task
        if (Task::s_taskRegistry) {
            Task::s_taskRegistry->removeTask(this);
            vTaskDelete((TaskHandle_t) this->m_handle);
        }

    }

    void Task::suspend(bool onPurpose)
    {
        // FW_ASSERT(0);
        vTaskSuspend((TaskHandle_t) this->m_handle);
    }

    void Task::resume(void)
    {
        // FW_ASSERT(0);
        vTaskResume((TaskHandle_t) this->m_handle);
    }

    bool Task::isSuspended(void)
    {
        // FW_ASSERT(0);
        return (eTaskGetState((TaskHandle_t) this->m_handle) == eSuspended);
    }

}