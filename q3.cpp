//Linear
#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1;  
    }
    return n; 
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7}; 
    int n = 7;  
    cout << "Missing Number (Linear): " << findMissingLinear(arr, n);
    return 0;
}



//Binary
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;  
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1)
            low = mid + 1;  
        else
            high = mid - 1; 
    }
    return low + 1; 
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;
    cout << "Missing Number (Binary Search): " << findMissingBinary(arr, n);
    return 0;
}





