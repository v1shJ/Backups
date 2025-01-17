

#include <bits/stdc++.h>
using namespace std;

void bankers(){
    int p, r;
    cout<<"Enter number of process and no of resources:";
    cin>>p>>r;
    int Max[p][r];
    int Allocation[p][r];
    int Need[p][r];
    int Available[r];
    int Finished[p];

    //Input Max Matrix
    cout<<"Max:"<<endl;
    cout<<"Process\t";
    for (int i = 0; i < r; i++){
        cout<<(char)(65+i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < p; i++){
        cout<<"P"<<i<<"\t";
        for (int j = 0; j < r; j++){
            cin>>Max[i][j];
        }
    }

    //Input Allocation Matrix
    cout<<"Allocation:"<<endl;
    cout<<"Process\t";
    for (int i = 0; i < r; i++){
        cout<<(char)(65+i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < p; i++){
        cout<<"P"<<i<<"\t";
        for (int j = 0; j < r; j++){
            cin>>Allocation[i][j];
        }
    }

    //Input Available Vector
    cout<<"Available:"<<endl;
    for (int i = 0; i < r; i++){
        cout<<(char)(65+i)<<" ";
    }
    cout<<endl;
    for (int j = 0; j < r; j++){
        cin>>Available[j];
    }

    //Calculate Need Matrix
    //Need = Max - Allocation
    for (int i = 0; i < p; i++){
        for (int j = 0; j < r; j++){
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    //Print Need Matrix
    cout<<"Need:"<<endl;
    cout<<"Process\t";
    for (int i = 0; i < r; i++){
        cout<<(char)(65+i)<<" ";
    }
    cout<<endl;
    for (int i = 0; i < p; i++){
        cout<<"P"<<i<<"\t";
        for (int j = 0; j < r; j++){
            cout<<Need[i][j]<<" ";
        }
        cout<<endl;
    }

    //Initialize Finished Matrix
    for (int i = 0; i < p; i++){
        Finished[i] = false;
    }

    int safe_count = 0;

    //Find which process can happen if Available >= Need
    bool safe = true;
    for (int k = 0; k < p; k++) {
        bool executed = false;

        for (int i = 0; i < p; i++) {
            if (Finished[i]) {
                continue;
            }

            bool can_execute = true;
            for (int j = 0; j < r; j++) {
                if (Need[i][j] > Available[j]) {
                    can_execute = false;
                    break;
                }
            }

            if (can_execute) {
                for (int j = 0; j < r; j++) {
                    Available[j] += Allocation[i][j];
                }
                Finished[i] = true;
                cout << "Process P" << i << " finished" << endl;
                executed = true;
            }
        }

        if (!executed) {
            safe = false;
            break;
        }
    }

    for (int i = 0; i < p; i++){
        safe = Finished[i];
        if (!safe){
            cout<<"System is not in safe state"<<endl;
            break;
        }
    }
    if (safe){
        cout<<"System is in safe state"<<endl;
    }

}

int main(void){
    bankers();
    return 0;
}

