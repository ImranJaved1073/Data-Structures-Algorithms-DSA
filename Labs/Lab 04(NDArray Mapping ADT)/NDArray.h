#ifndef NDARRAY_H
#define NDARRAY_H

#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class NDArray
{
    T *data;
    int noOfDimensions;
    int *sizeOfDimensions;
    int *startingIndex;
    int getRowMajorIndexMapping(const initializer_list<int> &list) const
    {
        int rowMajorIndex = 0;
        int dimensionMultiplier = 1;
        int i = 0;
        for (auto element : list)
        {
            for (int j = i + 1; j < noOfDimensions; j++)
            {
                dimensionMultiplier *= sizeOfDimensions[j];
            }
            rowMajorIndex += (element - startingIndex[i]) * dimensionMultiplier;
            dimensionMultiplier = 1;
            i++;
        }
        return rowMajorIndex;
    }

    bool isDimensionValid(int dim) const
    {
        return dim >= 0 && dim < noOfDimensions;
    }

    int getSizeOfDataStoredAs1DArray() const
    {
        int totalSize = 1;
        for (int i = 0; i < noOfDimensions; i++)
            totalSize *= sizeOfDimensions[i];
        return totalSize;
    }

public:
    NDArray(const initializer_list<T> firstList = {}, const initializer_list<T> secondList = {})
    {
        if (firstList.size() == 0)
        {
            noOfDimensions = 0;
            sizeOfDimensions = nullptr;
            startingIndex = nullptr;
            data = nullptr;
            return;
        }

        noOfDimensions = firstList.size();

        sizeOfDimensions = new int[noOfDimensions]{0};
        int i = 0;
        for (auto element : firstList)
            sizeOfDimensions[i++] = element;

        startingIndex = new int[noOfDimensions];
        i = 0;
        for (auto element : secondList)
            startingIndex[i++] = element;

        int totalSize = getSizeOfDataStoredAs1DArray();
        data = new T[totalSize];
    }

    int getNumberOfDimensions() const
    {
        return noOfDimensions;
    }

    int getDimensionSize(const int dimNo) const
    {
        if (isDimensionValid(dimNo))
            return sizeOfDimensions[dimNo];
        exit(0);
    }

    int getDimensionHigherIndex(const int dimNo) const
    {
        if (isDimensionValid(dimNo))
            return startingIndex[dimNo] + sizeOfDimensions[dimNo] - 1;
        exit(0);
    }

    int getDimensionLowerIndex(const int dimNo) const
    {
        if (isDimensionValid(dimNo))
            return startingIndex[dimNo];
        exit(0);
    }

    ~NDArray()
    {
        if (data)
            delete[] data;
        if (sizeOfDimensions)
            delete[] sizeOfDimensions;
        if (startingIndex)
            delete[] startingIndex;

        data = nullptr;
        sizeOfDimensions = nullptr;
        startingIndex = nullptr;
        noOfDimensions = 0;
    }

    NDArray(const NDArray<T> &ref)
    {
        noOfDimensions = ref.noOfDimensions;
        sizeOfDimensions = new int[noOfDimensions]{0};
        startingIndex = new int[noOfDimensions]{0};
        for (int i = 0; i < noOfDimensions; i++)
        {
            sizeOfDimensions[i] = ref.sizeOfDimensions[i];
            startingIndex[i] = ref.startingIndex[i];
        }
        int totalSize = getSizeOfDataStoredAs1DArray();
        data = new T[totalSize];

        if (ref.data == nullptr)
        {
            data = nullptr;
            return;
        }
        for (int i = 0; i < totalSize; i++)
            data[i] = ref.data[i];
    }

    NDArray<T> &operator=(const NDArray<T> &ref)
    {
        if (this != &ref)
        {
            this->~NDArray();

            noOfDimensions = ref.noOfDimensions;
            sizeOfDimensions = new int[noOfDimensions]{0};
            startingIndex = new int[noOfDimensions]{0};
            for (int i = 0; i < noOfDimensions; i++)
            {
                sizeOfDimensions[i] = ref.sizeOfDimensions[i];
                startingIndex[i] = ref.startingIndex[i];
            }
            int totalSize = getSizeOfDataStoredAs1DArray();
            data = new T[totalSize];

            if (ref.data == nullptr)
            {
                data = nullptr;
                return *this;
            }
            for (int i = 0; i < totalSize; i++)
                data[i] = ref.data[i];
        }
        return *this;
    }

    bool isIndexBoundsValid(const initializer_list<int> &list) const
    {
        if (list.size() != noOfDimensions)
            return false;
        int i = 0;
        for (auto element : list)
        {
            if (element < startingIndex[i] || element >= startingIndex[i] + sizeOfDimensions[i])
                return false;
            i++;
        }
        return true;
    }

    T &operator()(const initializer_list<int> &list)
    {
        if (!isIndexBoundsValid(list))
        {
            cout << "Index out of bounds" << endl;
            exit(0);
        }
        int index = getRowMajorIndexMapping(list);
        return data[index];
    }

    T operator()(const initializer_list<int> &list) const
    {
        if (!isIndexBoundsValid(list))
        {
            cout << "Index out of bounds" << endl;
            exit(0);
        }
        int index = getRowMajorIndexMapping(list);
        return data[index];
    }
};

#endif