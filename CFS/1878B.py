def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        result = []
        curr = 1  
        
        for _ in range(n):
            result.append(curr)
            curr += 2  
        
        print(" ".join(map(str, result)))

main()
