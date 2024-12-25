#ifndef __TIME_H
#define __TIME_H

#include "stm32f1xx_hal.h"
extern TIM_HandleTypeDef htim1;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif
