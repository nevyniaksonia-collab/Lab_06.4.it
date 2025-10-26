#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void create(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 20000 - 10000) / 100.0;
    }
}

void print(const double* arr, int n) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << setw(10) << arr[i];
    }
    cout << endl;
}

double sumNeg(const double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            sum += arr[i];
    return sum;
}

int findMaxIdx(const double* arr, int n) {
    if (n <= 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[maxIdx])
            maxIdx = i;
    return maxIdx;
}

int findMinIdx(const double* arr, int n) {
    if (n <= 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[minIdx])
            minIdx = i;
    return minIdx;
}

double productMinMax(const double* arr, int n) {
    if (n < 2) return 1.0;

    int maxIdx = findMaxIdx(arr, n);
    int minIdx = findMinIdx(arr, n);

    int start = (maxIdx < minIdx ? maxIdx : minIdx) + 1;
    int end = (maxIdx > minIdx ? maxIdx : minIdx) - 1;

    if (start > end)
        return 1.0;

    double prod = 1.0;
    for (int i = start; i <= end; i++)
        prod *= arr[i];

    return prod;
}

bool isEven(double val) {
    if (fmod(val, 1.0) != 0.0)
        return false;
    return static_cast<int>(val) % 2 == 0;
}

void sortEven(double* arr, int n) {
    double* evenVals = new double[n];
    int* evenIdxs = new int[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (isEven(arr[i])) {
            evenVals[count] = arr[i];
            evenIdxs[count] = i;
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (evenVals[j] > evenVals[j + 1])
                swap(evenVals[j], evenVals[j + 1]);

    for (int i = 0; i < count; i++)
        arr[evenIdxs[i]] = evenVals[i];

    delete[] evenVals;
    delete[] evenIdxs;
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    int n;

    cout << "Enter array size n: ";
    cin >> n;

    double* arr = new double[n];

    create(arr, n);

    cout << "\nInitial Array: " << endl;
    print(arr, n);

    double sum = sumNeg(arr, n);
    cout << "1.1. Sum of negative elements: " << fixed << setprecision(2) << sum << endl;

    double prod = productMinMax(arr, n);
    cout << "1.2. Product between min and max: " << fixed << setprecision(2) << prod << endl;

    sortEven(arr, n);

    cout << "Modified Array: " << endl;
    print(arr, n);

    delete[] arr;
    return 0;
}