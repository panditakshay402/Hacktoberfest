# Function to delete common elements from two given sorted lists.

def delete_common_elements(list1, list2):
    result = []
    i = 0 # Pointer for list1
    j = 0 # Pointer for list2
    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]:
            result.append(list1[i])
            i += 1
        elif list1[i] > list2[j]:
            result.append(list2[j])
            j += 1
        else:
            # Skip common element
            i += 1
            j += 1
    # Append remaining elements from list1
    while i < len(list1):
        result.append(list1[i])
        i += 1
        
    # Append remaining elements from list2
    while j < len(list2):
        result.append(list2[j])
        j += 1
        
    return result
    
    
list1 = [1, 3, 5, 7, 9]
list2 = [3, 6, 7, 8, 9, 10]
result = delete_common_elements(list1, list2)
print(result)