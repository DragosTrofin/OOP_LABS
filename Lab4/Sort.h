class Sort
{
    int* b, n;

public:
    Sort(int count, int mini, int maxi);
    Sort(int v[], int count);
    Sort(char* s);
    Sort(int count, ...);
    Sort() : b(new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), n(10){}
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false,int left=0,int right=9);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};