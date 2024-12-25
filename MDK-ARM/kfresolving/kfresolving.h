#ifndef __kfresolving_H
#define __kfresolving_H
extern  double pitch_g;
extern  double roll_g;
extern  double pitch_g_1;
extern  double roll_g_1;



void kf(void);
void kf_init(void);


void Kalman_Cal_Pitch(float acc,float gyro);
void Kalman_Cal_Roll(float acc,float gyro); //¿¨¶ûÂüÂË²¨rollÖá¼ÆËã	


#endif
