#include <iostream>
// Replace vector/unique_ptr with a single raw pointer and sized variable
double* data = nullptr;
int dataSize = 0;

int fitData(){
    std::cout << "Enter number of data points to fit: ";
    std::cin >> dataSize;
    if (data) delete[] data;
    data = new double[dataSize * 2];
    for(int i = 0; i < dataSize; ++i){
        std::cout << "Enter x and y for data point " << i+1 << ": ";
        std::cin >> data[2*i] >> data[2*i+1];
    }
    return dataSize;
}

void printData(){
    if (!data || dataSize == 0) {
        std::cout << "No data available. Fit data first." << std::endl;
        return;
    }
    std::cout << "Data" << std::endl;
    for (int i = 0; i < dataSize; i++) {
        std::cout << "Data " << i << ": x=" << data[2*i] << ", y=" << data[2*i+1] << std::endl;
    }
}

int main(){
    int userInput;
    std::cout << "Enter 1 to fit data or 2 to print data: ";
    std::cin >> userInput;
    switch(userInput){
    case 1:
        fitData();
        break;
    case 2:
        printData();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
    }
    delete[] data;
    return 0;
}