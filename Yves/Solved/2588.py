from sys import stdin

def main():
    A, B = stdin.readlines()

    B1, B2, B3, _ = list(B)

    R1 = int(A) * int(B3)
    R2 = int(A) * int(B2)
    R3 = int(A) * int(B1)
    R4 = R1 + 10 * R2 + 100 * R3

    print(R1)
    print(R2)
    print(R3)
    print(R4)
    
    return 0

if __name__ == "__main__":
    main()