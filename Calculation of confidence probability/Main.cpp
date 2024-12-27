//MIT License
//Copyright(c) 2024 ineedmypills

#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

void calculateConfidenceInterval(double mean, double stddev, int sampleSize, double confidenceLevel) {
    double z;
    if (confidenceLevel == 0.90) z = 1.645;
    else if (confidenceLevel == 0.95) z = 1.96;
    else if (confidenceLevel == 0.99) z = 2.576;
    else {
        cout << "�������� ������� �������!";
        return;
    }

    double standardError = stddev / sqrt(sampleSize);
    double marginOfError = z * standardError;
    double lowerBound = mean - marginOfError;
    double upperBound = mean + marginOfError;

    cout << "������������� ��������: [" << lowerBound << ", " << upperBound << "]";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double mean, stddev, confidenceLevel;
    int sampleSize;

    cout << "������� ������� �������� �������: ";
    cin >> mean;
    cout << "������� ���������� �������: ";
    cin >> stddev;
    cout << "������� ������ �������: ";
    cin >> sampleSize;
    cout << "������� ������� ������� (0.90, 0.95, 0.99): ";
    cin >> confidenceLevel;

    calculateConfidenceInterval(mean, stddev, sampleSize, confidenceLevel);

    return 0;
}