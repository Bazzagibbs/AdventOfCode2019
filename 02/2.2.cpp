#include <iostream>
#include <vector>
using namespace std;

int runIntcode(vector<int> inputs, int noun, int verb){

    inputs[1] = noun;
    inputs[2] = verb;

    // opcodes
    // 1: ADD numbers at next two pointers, store in the index pointed by third.
    // 2: MULT numbers at next two pointers
    // 99: RETURN
    for(int i = 0; i < inputs.size(); i+=4){
        int a, b, retIndex;
        bool halt = false;

        switch(inputs[i]){
            case 1:
                a = inputs[inputs[i+1]];
                b = inputs[inputs[i+2]];
                retIndex = inputs[i+3];

                inputs[retIndex] = a + b;
                break;

            case 2:
                a = inputs[inputs[i+1]];
                b = inputs[inputs[i+2]];
                retIndex = inputs[i+3];

                inputs[retIndex] = a * b;
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
    return inputs[0];
}

int main(){
    vector<int> inputs;
    int temp;
    char trash;
    while(cin >> temp){
        inputs.push_back(temp);
        if(cin) cin >> trash;
    }
    vector<int> backup = inputs;
    int i, j;
    bool solved = false;
    for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){
            inputs = backup;
            if(runIntcode(inputs, i, j) == 19690720){
                solved = true;
                break;
            }
        }
        if(solved) break;
    }

    cout << "Inputs that produce output 19690720: " << i << ", " << j << '\n';
    cout << "Challenge result: " << (100 * i + j) << '\n';

    return 0;
}
