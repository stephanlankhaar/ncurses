#include<iostream>
#include<algorithm> 
using namespace std; 
 
int main(){ 
    int arr[] = {10, 324, 45, 90, 9808}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int max= *max_element(arr,arr+n);
    cout<<max+1;
    return 0; 
} 
