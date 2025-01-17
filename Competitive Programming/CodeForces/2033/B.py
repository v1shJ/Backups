def min_magic_operations(test_cases):
    results = []
    
    for n, matrix in test_cases:
        operations = 0
        
        # We will go through the matrix from bottom-right to top-left
        for i in reversed(range(n)):
            for j in reversed(range(n)):
                if matrix[i][j] < 0:
                    # Calculate how many operations needed to make this element zero
                    required_operations = -matrix[i][j]
                    operations += required_operations
                    
                    # Apply these operations to the diagonal elements
                    k = 0
                    while i + k < n and j + k < n:
                        matrix[i + k][j + k] += required_operations
                        k += 1
        
        results.append(operations)
    
    return results

# Example input processing
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    test_cases.append((n, matrix))

results = min_magic_operations(test_cases)
for res in results:
    print(res)
