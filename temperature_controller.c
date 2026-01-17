#include <stdio.h>

int main() {
    float current_temp = 34.0;
    float desired_temp = 45.0;
    
    float heat_rate = 0.66;
    float cool_rate = 0.2;

    float prev_error = desired_temp - current_temp;
    float dt = 0.1;
    
    float Ki=0.002, Kd=0.35;
    float integral = 0.0;
    float heater_power = 0.0, control_output=0.0; 
    
    
    for (float i = 0;i <= 900; i+=1) {
        
        float error = desired_temp - current_temp;
        float Kp=(error > 10) ?1.0 :2.0;
        float P = error*Kp;
        
        integral += error*dt;
        float I = Ki * integral;
        
        float D = Kd*(error - prev_error)/dt;
        control_output = P + I + D;
        prev_error = error;
        
        if (control_output>heat_rate){
            heater_power=heat_rate;
        }
        else if(control_output<0.0)
            heater_power = 0.0;
        else
            heater_power = control_output;
        
        current_temp = current_temp + (heater_power -cool_rate)*dt;

        
        printf("Time %.1f sec -> Temperature: %.3f\n", i, current_temp);
    }

    return 0;
}
