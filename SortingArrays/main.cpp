#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void createManualArray(int sizeOfArray)
{
    int *arr = new int[sizeOfArray];

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        cout << "Podaj wartosc elementu " << i + 1 << "-ego: ";
        cin >> arr[i];
    }

    cout << endl << "Wypisanie wprowadzonej tablicy:" << endl;
    for(int i = 0 ; i < sizeOfArray ; i++) cout << "Wartosc nr " << i + 1 << ": " << arr[i] << endl;

    quickSort(arr,0,sizeOfArray - 1);
    cout << "Element najmniejszy: " << arr[0] << endl << "Element najwiekszy: " << arr[sizeOfArray - 1] << endl;
    cout << endl << "Wypisanie wprowadzonej i posortowanej tablicy:" << endl;
    for(int i = 0 ; i < sizeOfArray ; i++) cout << "Wartosc nr " << i + 1 << ": " << arr[i] << endl;

    delete [] arr;
}

void createAutoArray(int sizeOfArray,int rangeFrom,int rangeTo)
{
    int *arr = new int[sizeOfArray];

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        arr[i] = rand() % (rangeTo + 1) + rangeFrom;
    }

    cout << endl << "Wypisanie wprowadzonej tablicy:" << endl;
    for(int i = 0 ; i < sizeOfArray ; i++) cout << "Wartosc nr " << i + 1 << ": " << arr[i] << endl;

    quickSort(arr,0,sizeOfArray - 1);
    cout << "Element najmniejszy: " << arr[0] << endl << "Element najwiekszy: " << arr[sizeOfArray - 1] << endl;
    cout << endl << "Wypisanie wprowadzonej i posortowanej tablicy:" << endl;
    for(int i = 0 ; i < sizeOfArray ; i++) cout << "Wartosc nr " << i + 1 << ": " << arr[i] << endl;

    delete [] arr;
}

int main()
{
    bool killProcess = false;
    while(!killProcess)
    {
    int userInput = 0, sizeOfArray = 0, rangeFrom, rangeTo;
        cout <<
                "-----------------------------------------------------------------\n"
                "Zadanie 2:\n"
                ">> Podaj numer wybranego polecenia i zatwierdz klawiszem ENTER <<\n"
                "1) Tablica z wartosciami z klawiatury\n"
                "2) Tablica z losowymi wartosciami\n"
                "3) Zakoncz program\n"
             << endl;
    cin >> userInput;
        switch (userInput) {
        case 1:
            cout << "Podaj rozmiar tablicy (ilosc liczb): ";
            cin >> sizeOfArray;
            cout << endl;
            createManualArray(sizeOfArray);
            break;
        case 2:
            cout << "Podaj rozmiar tablicy (ilosc liczb): ";
            cin >> sizeOfArray;
            cout << endl << ">> Podaj zakres liczb" << endl << "Od: ";
            cin >> rangeFrom;
            cout << "Do: ";
            cin >> rangeTo;
            createAutoArray(sizeOfArray,rangeFrom,rangeTo);
            break;
        case 3:
            killProcess = true;
            break;
        default:
            cout << "NIEPOPRAWNA WARTOSC!\nSprobuj ponownie ^^" << endl;
            break;
        }
    }
    return 0;
}
