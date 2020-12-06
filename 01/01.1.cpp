#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int getFuel(int weight){
    int moreFuel = weight/3-2;
    
    if(moreFuel > 0){
        return moreFuel + getFuel(moreFuel);
    }
    return 0;
}

int main(){
    int temp = 0;
    int opCount = 0;
    long fuel = 0;
    while(cin >> temp){
        opCount++;
        fuel+=getFuel(temp); 
    }



    cout << fuel << "\n" << opCount << "\n";
    
    return 0;
}
