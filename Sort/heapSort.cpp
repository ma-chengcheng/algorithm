void adjust(vector<int> &arr, int len, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx])
        maxIdx = right;

    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}

void heapSort(vector<int> &arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 调整大根堆
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }
}
