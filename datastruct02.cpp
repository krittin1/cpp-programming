#include <iostream>
using namespace std ;
int main () {
    
    
    int bee, n ;
    int total=0;
    cin >> n >> bee ;
    int ls1[bee], ls2[bee] ;
    for(int i=0; i<bee; i++) {
        cin >> ls1[i] >> ls2[i] ;
    }
    for (int i=0; i<bee; i++) {
        for(int j=i; j<bee; j++) {
            if((ls1[i] == ls2[j]) && (ls1[j] == ls2[i]) && (ls1[i] != 0) && ls1[j] != 0) {
                ls1[i] = 0 ;
                ls1[j] = 0 ;
                ls2[i] = 0 ;
                ls2[j] = 0 ;
                 total++ ;
            }

        }
    }
    
    if((bee/2 == total) && (bee%2 == 0)) {
        cout << "No" ;
    }
    else {
        cout << "Yes" ;
    }
   
    
}


