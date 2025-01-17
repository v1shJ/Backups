#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    long long int n; long long int m;
	    cin >> n >> m;
	    long long int candy[n]; long long int choc[n];
	    for(long long int i = 0; i < n; i++){
	        cin >> candy[i];
	    }
	    for(long long int j = 0; j < n; j++){
	        cin >> choc[j];
	    }
	    
	    long long int count = 0;
	    for(long long int c = 0; c < n; c++){
	        for(long long int a = 0; a < n; a++){
    	        if((candy[c] + choc[a]) % m == 0){
    	            count++;
    	        }
	        }
	    }
	    cout << count << endl;
	}
}
