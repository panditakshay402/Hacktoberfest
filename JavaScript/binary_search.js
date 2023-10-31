function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (arr[mid] === target) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Adjust the left boundary
        } else {
            right = mid - 1; // Adjust the right boundary
        }
    }

    return -1; // Target not found in the array
}

// Example usage:
const sortedArray = [1, 3, 5, 7, 9, 11, 13, 15];
const targetValue = 7;

const result = binarySearch(sortedArray, targetValue);

if (result !== -1) {
    console.log(`Target ${targetValue} found at index ${result}.`);
} else {
    console.log(`Target ${targetValue} not found in the array.`);
}
