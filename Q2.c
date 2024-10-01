#include <stdio.h>

// Function prototypes
void display(int arr[], int size);
void insert(int arr[], int *size, int index, int value);
void delete(int arr[], int *size, int index);
int search(int arr[], int size, int value);
void update(int arr[], int size, int index, int newValue);

int main()
{
    int arr[100]; // Array with a maximum size of 100
    int size = 0; // Current size of the array

    // Initializing the array with some values
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    size = 3;

    printf("Initial array:\n");
    display(arr, size);

    // Inserting a new element at index 1
    insert(arr, &size, 1, 15);
    printf("\nAfter inserting 15 at index 1:\n");
    display(arr, size);

    // Deleting the element at index 2
    delete (arr, &size, 2);
    printf("\nAfter deleting the element at index 2:\n");
    display(arr, size);

    // Searching for an element in the array
    int index = search(arr, size, 20);
    if (index != -1)
    {
        printf("\nElement 20 found at index %d.\n", index);
    }
    else
    {
        printf("\nElement 20 not found.\n");
    }

    // Updating the element at index 1
    update(arr, size, 1, 25);
    printf("\nAfter updating the element at index 1 to 25:\n");
    display(arr, size);

    return 0;
}

// Function to display the elements of the array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified index
void insert(int arr[], int *size, int index, int value)
{
    if (*size >= 100)
    {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (index < 0 || index > *size)
    {
        printf("Invalid index, cannot insert.\n");
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = *size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
}

// Function to delete an element at a specified index
void delete(int arr[], int *size, int index)
{
    if (index < 0 || index >= *size)
    {
        printf("Invalid index, cannot delete.\n");
        return;
    }
    // Shift elements to the left to fill the gap
    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to search for an element in the array
int search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to update an element at a specified index
void update(int arr[], int size, int index, int newValue)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index, cannot update.\n");
        return;
    }
    arr[index] = newValue;
}