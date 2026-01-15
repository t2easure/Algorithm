def decimal_to_base_N(N, B):
    Numlist = []
    
    while N > 0:
        remainder = N % B
        if remainder >= 10:
            Numlist.append(chr(remainder + ord('A') - 10))
        else:
            Numlist.append(str(remainder))
        N //= B
    
    result = ''.join(reversed(Numlist))
    return result

N, B = map(int, input().split())

result = decimal_to_base_N(N, B)
print(result)