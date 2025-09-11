void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


/*---------------- Search -----------------*/


// ______Linear______

int Search_Lin(int n, int *arr, int LOC, int ITEM)
{
    arr[n] = ITEM;

    while(arr[LOC] != ITEM)
    {
        LOC += 1;
    }

    if(LOC == n)
       return -1;
    else
        return LOC+1;
}


// ______Binary______

int Search_Bin(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x) {
            return mid;
        }
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


/*---------------- Sortion ----------------*/


// ______Bubble______

void Sort_Bubble(int arr[], int n)
{
    int i, j;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


// ______Selection_____

void Sort_Sel(int *arr, int n)
{
    int i, j;
    
    for(i=0; i<n-1; i++)
    {
        int mini = i;
        
        for(j=i+1; j<n; j++)
        {
            if(*(arr+j) < *(arr+mini))
                mini=j;
        }
        swap(arr+i, arr+mini);
    }
}


// ______Insertion______

void Sort_In(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}


// ______Quick______

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement QuickSort
void Sort_Quick(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        Sort_Quick(arr, low, pi - 1);
        Sort_Quick(arr, pi + 1, high);
    }
}


// ______Radix______

// Function to find the maximum element in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void Sort_Radix(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


// ______Merge Sort______

// Function to merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void Sort_Merge(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        Sort_Merge(arr, l, m);
        Sort_Merge(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}


// ______Heap______

// Function to heapify a subtree rooted with node i which is an index in arr[]. n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap arr[i] and arr[largest]
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void Sort_Heap(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


/* How to pass arguments

    Sort_Bubble(arr, size)
    Sort_In(arr, size)
    Sort_Sel(arr, size)
    Sort_Quick(arr, 0, size-1)
    Sort_Radix(arr, size)
    Sort_Merge(arr, 0, size-1)
    Sort_Heap(arr, size)
    
*/