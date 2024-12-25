#include "time.h"
#include "main.h"
#include "kfresolving.h"
#include "mpu6050.h"
#include "math.h"
#include "tim.h"

double roll_raw,pitch_raw;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim==&htim1)
	{
		
//        kf();
	
		
		MPU6050_Read_Accel();
		MPU6050_Read_Gyro();
		
		//将加速度得出来的角度作为观测值
		roll_raw = atan(Mpu6050_Data.Accel_Y/Mpu6050_Data.Accel_Z)*180/3.14;
	    pitch_raw = -atan(Mpu6050_Data.Accel_X/sqrt(Mpu6050_Data.Accel_Y*Mpu6050_Data.Accel_Y+Mpu6050_Data.Accel_Z*Mpu6050_Data.Accel_Z))*180/3.14;
		//调用卡尔曼函数
		Kalman_Cal_Pitch(pitch_raw,Mpu6050_Data.Gyro_X);  //卡尔曼滤波计算X倾角
		Kalman_Cal_Roll(roll_raw,Mpu6050_Data.Gyro_Y);  //卡尔曼滤波计算Y倾角
		
	}

}
