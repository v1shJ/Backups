from collections import Counter

def solve(n, k, cards):
    # Count frequencies of each number on the cards
    freq = Counter(cards)
    # Extract unique values and sort them
    unique_values = sorted(freq.keys())
    
    max_cards = 0
    left = 0
    total_cards = 0

    for right in range(len(unique_values)):
        total_cards += freq[unique_values[right]]

        # Maintain the count of distinct numbers within the limit of k
        while (right - left + 1 > k) or (unique_values[right] - unique_values[left] > 1):
            total_cards -= freq[unique_values[left]]
            left += 1

        # Update the maximum cards taken
        max_cards = max(max_cards, total_cards)

    return max_cards

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    cards = list(map(int, input().split()))
    result = solve(n, k, cards)
    print(result)
