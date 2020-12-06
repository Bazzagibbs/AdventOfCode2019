#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> inputs;
    int temp;
    char trash;
    while(cin >> temp){
        inputs.push_back(temp);
        if(cin) cin >> trash;
    }

    // opcodes
    // 1: ADD numbers at next two pointers, store in the index pointed by third.
    // 2: MULT numbers at next two pointers
    // 99: RETURN

    cout << inputs.size();
    for(int i = 0; i < inputs.size(); i+=4){
        int a, b, retIndex;
        bool halt = false;
        cout << i/4 << ":\t";

        switch(inputs[i]){
            case 1:
                a = inputs[inputs[i+1]];
                b = inputs[inputs[i+2]];
                retIndex = inputs[i+3];

                inputs[retIndex] = a + b;
                cout << "Adding " << a << " + " << b <<" = " << inputs[retIndex] << " --> [" << retIndex <<"]\n";
                break;

            case 2:
                a = inputs[inputs[i+1]];
                b = inputs[inputs[i+2]];
                retIndex = inputs[i+3];

                inputs[retIndex] = a * b;
                cout << "Multiplying " << a << " * " << b <<" = " << inputs[retIndex] << " --> [" << retIndex <<"]\n";
                break;

            case 99:
                halt = true;
                break;
            default:
                cout << "Whoops\n";
                break;
        }
        if(halt) break;
    }
    cout <<"Final output: " <<  inputs[0] << "\n";
    return 0;
}
