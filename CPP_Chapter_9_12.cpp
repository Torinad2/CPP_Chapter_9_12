/*************************************************************
 * Element Shifter Program                                   *
 *                                                           *
 * This program defines a function called `elementShifter`   *
 * that accepts an integer array and its size. It creates a  *
 * new array that is one element larger than the original    *
 * array. The first element is set to `0`, and the remaining *
 * elements are shifted by one position.                     *
 *                                                           *
 * Developed by: Nikita Baiborodov                           *
 *************************************************************/

#include <iostream>
using namespace std;

/*************************************************************
 * Function Prototypes                                       *
 *************************************************************/
int* elementShifter(const int*, int); // Shifts elements and adds `0` as the first element
void displayArray(const int*, int);   // Displays the contents of an array

/*************************************************************
 * Main Function                                             *
 * Handles input and initiates the element shift process.    *
 *************************************************************/
int main() {
    int size;

    /*************************************************************
     * Display Program Information                               *
     *************************************************************/
    cout << "Element Shifter Program\n";
    cout << "------------------------\n";

    /*************************************************************
     * Input: Get the size of the array                          *
     *************************************************************/
    cout << "Enter the size of the array (must be > 0): ";
    cin >> size;

    while (size <= 0) {  // Ensure size is greater than 0
        cout << "Error: Size must be greater than 0. Please try again: ";
        cin >> size;
    }

    /*************************************************************
     * Dynamically allocate the original array                  *
     *************************************************************/
    int* arr = new int[size];

    /*************************************************************
     * Input: Get the array elements from the user              *
     *************************************************************/
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> *(arr + i);
    }

    /*************************************************************
     * Create the shifted array using elementShifter            *
     *************************************************************/
    int* shiftedArr = elementShifter(arr, size);

    /*************************************************************
     * Output: Display the original and shifted arrays          *
     *************************************************************/
    cout << "\nOriginal Array: ";
    displayArray(arr, size);

    cout << "Shifted Array : ";
    displayArray(shiftedArr, size + 1);

    /*************************************************************
     * Free dynamically allocated memory                        *
     *************************************************************/
    delete[] arr;
    delete[] shiftedArr;

    /*************************************************************
     * Developer Signature                                       *
     *************************************************************/
    cout << "\nDeveloped by: Nikita Baiborodov\n";

    /*************************************************************
     * End of Program                                            *
     *************************************************************/
    return 0;
}

/*************************************************************
 * elementShifter                                            *
 *                                                           *
 * This function accepts an integer array and its size. It   *
 * creates a new array that is one element larger than the   *
 * original. The first element is set to `0`, and the        *
 * remaining elements are copied over.                       *
 *                                                           *
 * Returns a pointer to the new array.                       *
 *************************************************************/
int* elementShifter(const int* arr, int size) {

    int* newArray = nullptr;

    // Validate the size. If 0 or a negative
    // number was passed, return a null pointer.
    if (size <= 0)
        return nullptr;

    // Allocate new array (one element larger)
    newArray = new int[size + 1];

    // Set the first element to 0
    *newArray = 0;

    // Copy elements using pointer notation
    for (int index = 0; index < size; index++) {
        *(newArray + index + 1) = *(arr + index);
    }

    // Return a pointer to the new array.
    return newArray;
}

/*************************************************************
 * displayArray                                              *
 *                                                           *
 * This function accepts an integer array and its size. It   *
 * displays the contents of the array in a single line.      *
 *************************************************************/
void displayArray(const int* arr, int size) {
    for (int index = 0; index < size; index++) {
        cout << *(arr + index) << " ";
    }
    cout << endl;
}
