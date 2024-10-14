#include <iostream>
#include <math.h>
#include <cstdlib>
#include "capacitor.h"
using namespace std;


int main(){
    
    double deltat = pow( 10, -10);
    double finaltime = 5*pow(10, -6);
    int timesteps = 50000;
    double R = 1000;
    double currentsupply = 0.01;
    double voltagesupply = 10;



Capacitor capacitor1;

capacitor1.time = new double [timesteps + 1];
capacitor1.voltage = new double [timesteps + 1];
capacitor1.current = new double [timesteps + 1];

int i;
capacitor1.voltage[0] = 10;
capacitor1.current[0] = 0.01;
capacitor1.C = 100*pow(10, -12);



for ( i = 0; i < timesteps + 1; i++){

    capacitor1.time[i] = deltat * i;
        
}

for (i = 0 ;  i < timesteps + 1 ; i++){

    capacitor1.current[i+1] = capacitor1.current[i] - ((capacitor1.current[i] * deltat)/(R * capacitor1.C));

    capacitor1.voltage[i+1] = capacitor1.voltage[i] + (capacitor1.current[i] * deltat)/capacitor1.C;

    if( i % 200 == 0){

        cout << "TIMESTEP:" << i << " / "<<  "TIME: " << capacitor1.time[i] << " s / " << "CURRENT: " << capacitor1.current[i] << " A /" << " VOLTAGE: " << capacitor1.voltage[i] << " V\n";
    }

}

for (i = 0; i < timesteps + 1 ; i++){

    delete[] capacitor1.current;
    delete[] capacitor1.voltage;
    delete[] capacitor1.time; 
}

    return 0;
}
