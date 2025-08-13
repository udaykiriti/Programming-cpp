

"""
Problem: Dragons
Kirito is stuck in a video game and needs to defeat dragons to progress. Each dragon has a strength and a bonus.
Kirito starts with an initial strength `s`. If Kirito's strength is greater than a dragon's strength, he defeats it
and gains the bonus. Otherwise, he loses the game.

Input:
The first line contains two integers `s` and `n` (1 ≤ s ≤ 10^4, 1 ≤ n ≤ 10^3) — Kirito's initial strength and the number of dragons.
The next `n` lines each contain two integers `a` and `b` (1 ≤ a, b ≤ 10^4) — the strength of a dragon and the bonus Kirito gains after defeating it.

Output:
Print "YES" if Kirito can defeat all dragons, otherwise print "NO".

Example:
Input:
2 2
1 99
100 0
Output:
YES

Input:
10 1
100 100
Output:
NO
"""

def main():
    # Read Kirito's initial strength and the number of dragons
    s, n = map(int, input().split())
    
    # Read the dragons' strength and bonus
    dragons = []
    for _ in range(n):
        a, b = map(int, input().split())
        dragons.append((a, b))
    
    # Sort dragons by their strength
    dragons.sort()
    
    # Check if Kirito can defeat all dragons
    for strength, bonus in dragons:
        if s > strength:
            s += bonus  # Gain bonus after defeating the dragon
        else:
            print("NO")
            return
    
    print("YES")

if __name__ == "__main__":
    main()