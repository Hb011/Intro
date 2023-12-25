//cau1
write a complete program meeting the following requirements
a.input 1 positive integer n and K so that 0<n<1000; if the input value is not compliant to the rule, ask the user to input again until the rule is satisfied
b.print out the sum S=11+22+33+....+nn 
 example: N=4 -> S=11+22+33+44=1000
          N=12 -> S=11+22+33+1010+1111+1212=3828
          
/*
#include <iostream>

int main() {
    int n, k;

    // Input validation loop
    do {
        std::cout << "Enter a positive integer (0 < n < 1000): ";
        std::cin >> n;
        std::cout << "Enter another positive integer (k): ";
        std::cin >> k;
    } while (n <= 0 || n >= 1000);

    int sum = 0;
    int num = 11;

    // Calculate and print the sum
    for (int i = 1; i <= n; ++i) {
        sum += num * i;
    }

    std::cout << "S = " << sum << std::endl;

    return 0;
}
*/


//cau2
write a complete program meeting the following requirements
a. input an integer array with N elements, the output that array onto the console screen
b. find and print out the element that contains most digits with 0 value. In case there are more than one such elements, print out the last one
  example: 200 35 80 22 1010 7   ->   1010 (2zero digits)
c.sort the array so that prime elements are in descending order, while other elements remain unchanged. Then, print out the resulting array 
   example:  5 8 3 9 6 7 1
        ->   7 8 5 9 6 3 1

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to count the number of zero digits in an integer
int countZeroDigits(int num) {
    int count = 0;
    while (num != 0) {
        if (num % 10 == 0) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;

  // Input the size of the array
    do {
      std::cout << "Enter the size of the array: ";
      std::cin >> N;
    } while (N <= 0 || N >= 1000);

    // Input the array elements
    std::vector<int> arr(N);
    std::cout << "Enter " << N << " integer elements: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    // Output the array
    std::cout << "Array elements: ";
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int maxZeroDigitsElement = 0;
    int maxZeroDigitsCount = -1;

    // Find the element with the most zero digits
    for (int i = 0; i < N; ++i) {
        int zeroDigitsCount = countZeroDigits(arr[i]);
        if (zeroDigitsCount > maxZeroDigitsCount || (zeroDigitsCount == maxZeroDigitsCount && i > maxZeroDigitsElement)) {
            maxZeroDigitsCount = zeroDigitsCount;
            maxZeroDigitsElement = i;
        }
    }

    // Output the element with the most zero digits
    std::cout << "Element with the most zero digits: " << arr[maxZeroDigitsElement] << " (" << maxZeroDigitsCount << " zero digits)" << std::endl;

    // Sort the array with prime elements in descending order
    std::sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (isPrime(a) && isPrime(b)) {
            return a > b;
        } else if (isPrime(a)) {
            return true;
        } else if (isPrime(b)) {
            return false;
        } else {
            return false; // Non-prime elements remain unchanged
        }
    });

    // Output the sorted array
    std::cout << "Sorted array with prime elements in descending order: ";
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/

//cau3
write a complete program meeting the following requirements
a. declare and input values for a NxM matrix which contains integers, then output it onto the console screen
b. check if the input matrix is an "X" matrix or not, with the definition tha an S matrix is a square matrix in which all the elements on 2 diagonas are non-zero and all the other elements must be zeroes
  example: -3  0  0  0  3
           0  5  0  -2  0
           0  0  4  0  0
           2  0  0  0  6
           output: yes

/*
##include <iostream>
#include <vector>

int main() {
    int N;

    // Input the size of the matrix
    std::cout << "Enter the size of the matrix (N): ";
    std::cin >> N;

    // Input the matrix elements
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    std::cout << "Enter integer elements for the matrix:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Row " << i+1 << " : " << std::endl;
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Output the matrix
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Check if the matrix is an "X" matrix
    bool isXMatrix = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j && i != N - j - 1) {
                // Check if non-diagonal elements are zero
                if (matrix[i][j] != 0) {
                    isXMatrix = false;
                    break;
                }
            } else {
                // Check if diagonal elements are non-zero
                if (matrix[i][j] == 0) {
                    isXMatrix = false;
                    break;
                }
            }
        }
        if (!isXMatrix) {
            break;
        }
    }

    // Output the result
    if (isXMatrix) {
        std::cout << "Yes, the matrix is an 'X' matrix." << std::endl;
    } else {
        std::cout << "No, the matrix is not an 'X' matrix." << std::endl;
    }

    return 0;
}
*/


//cau4
write a complete program meeting the following requirements
a.declare and input value for a string containing no more than 200 characters
calculate and print out the greatest NON-NEGATIVE NUMBER that appears in the string
  example: input: Class 12A1 school year 2022-2023
           output: 2023

/*
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Function to extract non-negative numbers from a string
std::vector<int> extractNumbers(const std::string& str) {
    std::vector<int> numbers;
    std::istringstream iss(str);

    while (!iss.eof()) {
        int num;
        iss >> num;

        if (!iss.fail()) {
            if(num < 0) {
              num = num * -1;
            }
            numbers.push_back(num);
        } else {
            iss.clear();
            iss.ignore();
        }
    }

    return numbers;
}

int main() {
    std::string inputString;

    // Input a string containing no more than 200 characters
    std::cout << "Enter a string (no more than 200 characters): ";
    std::getline(std::cin, inputString);

    // Extract non-negative numbers from the string
    std::vector<int> numbers = extractNumbers(inputString);
  
    // Find the greatest non-negative number
    int greatestNonNegativeNumber = -1;
    for (int num : numbers) {
        std::cout << num << std::endl;
      
        if (num >= 0 && num > greatestNonNegativeNumber) {
            greatestNonNegativeNumber = num;
            
        }
    }

    // Print out the result
    if (greatestNonNegativeNumber >= 0) {
        std::cout << "The greatest non-negative number in the string is: " << greatestNonNegativeNumber << std::endl;
    } else {
        std::cout << "No non-negative numbers found in the string." << std::endl;
    }

    return 0;
}

*/


