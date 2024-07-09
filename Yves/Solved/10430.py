def main():
    A, B, C = list(map(int, input().split()))

    first = (A + B) % C
    second = ((A % C) + (B % C)) % C
    third = (A*B) % C
    fourth = ((A % C)*(B % C)) % C
    result = f"{first}\n{second}\n{third}\n{fourth}"
    return result


if __name__ == "__main__":
    print(main())