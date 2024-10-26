# Python program for implementation of Merge Sort

def mergeSort(arr):
    # Check if the array has more than one element
    if len(arr) > 1:

        # Finding the mid index of the array
        mid = len(arr) // 2

        # Dividing the array elements into two halves
        L = arr[:mid]  # Left half
        R = arr[mid:]  # Right half

        # Recursively sorting the first half
        mergeSort(L)

        # Recursively sorting the second half
        mergeSort(R)

        # Initializing indices for left (L), right (R), and merged array (arr)
        i = j = k = 0

        # Merging the temp arrays back into arr
        while i < len(L) and j < len(R):
            # Compare elements from both halves and merge them in sorted order
            if L[i] <= R[j]:
                arr[k] = L[i]  # If left element is smaller or equal
                i += 1  # Move to the next element in left half
            else:
                arr[k] = R[j]  # If right element is smaller
                j += 1  # Move to the next element in right half
            k += 1  # Move to the next position in merged array

        # Checking if any element was left in L
        while i < len(L):
            arr[k] = L[i]  # Copy remaining elements from L
            i += 1  # Move to next element in left half
            k += 1  # Move to next position in merged array

        # Checking if any element was left in R
        while j < len(R):
            arr[k] = R[j]  # Copy remaining elements from R
            j += 1  # Move to next element in right half
            k += 1  # Move to next position in merged array

# Function to print the elements of the list
def printList(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")  # Print each element followed by a space
    print()  # Print newline after the list

# Driver Code
if __name__ == '__main__':
    arr = [12, 11, 13, 5, 6, 7]  # Sample input array
    print("Given array is")
    printList(arr)  # Print the original array
    mergeSort(arr)  # Sort the array using merge sort
    print("\nSorted array is ")
    printList(arr)  # Print the sorted array
