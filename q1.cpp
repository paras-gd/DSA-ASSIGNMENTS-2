#include<iostream>
using namespace std;

int linearsearch(int arr[] , int n , int target) {
    for(int i = 0 ; i<n ; i++) {
        if(arr[i] == target) {
            return i ;
        }
        return -1 ;
    }
}

int binarysearch(int arr[] , int n , int target) {
    int low = 0 ;
    int high = n - 1 ;
    while(low <= high) {
        int mid = low + (high - low)/2 ;
        if(arr[mid] == target) {
            return mid ;
        }
        else if(arr[mid] < target) {
            low = mid + 1 ;
        }
        else {
            high = mid - 1 ;
        }
    }

    return -1 ;
}

int main() {

    int arr[] = {3,5,6,8,9,12,14,17,19,24,28,30} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    int target = 15 ;

    binarysearch(arr , n , target) ;
    

    return 0;
}
