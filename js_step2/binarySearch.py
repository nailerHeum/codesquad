arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]

def binarySearch(array, value, low, high):
    if low > high:
        return False
    mid = (low+high) // 2
    print(len(arr))
    if mid == len(arr):
        return False
    if array[mid] > value:
        return binarySearch(array, value, low, mid-1)
    elif array[mid] < value:
        return binarySearch(array, value, mid+1, high)
    else:
        return mid
        
binarySearch(arr, 11, 0, 9)