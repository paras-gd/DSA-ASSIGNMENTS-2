#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j])
                break;
        }
        if (j == i)
            count++;
    }

    cout << "Total distinct elements: " << count;
}
