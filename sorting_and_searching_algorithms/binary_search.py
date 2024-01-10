def iterative_binary_search(lista, target):
  
    # starting indices for lefmost and righmost list spots  
    left = 0
    right = len(lista) - 1

    while left <= right:
        middle = (left + right) // 2
        if lista[middle] == target:
            return target
        elif lista[middle] > target:
            right = middle - 1
        elif lista[middle] < target:
            left = middle + 1

    return -1

def recursive_binary_search(lista, target):
    
    # starting indices for lefmost and righmost list spots  
    left = 0
    right = len(lista) - 1

    if left > right:
        return -1
    else:
        middle = (left + right) // 2
        if lista[middle] == target:
            return target
        elif lista[middle] > target:
            lista = lista[:middle]
            return recursive_binary_search(lista, target)
        elif lista[middle] < target:
            lista = lista[middle + 1:len(lista)]
            return recursive_binary_search(lista, target)
        

lista = [1, 3, 6, 10, 14, 23, 25, 28, 30, 31, 37]

# Tests
print("Iterative Binary Search")
print(iterative_binary_search(lista, 25))
print(iterative_binary_search(lista, 24))
print(iterative_binary_search(lista, 31))
print(iterative_binary_search(lista, 0))
print(iterative_binary_search(lista, 3))
print("Recursive Binary Search")
print(recursive_binary_search(lista, 25))
print(recursive_binary_search(lista, 24))
print(recursive_binary_search(lista, 31))
print(recursive_binary_search(lista, 0))
print(recursive_binary_search(lista, 3))


