stringa = "parallelepipedo"
num = len(stringa)
for i in range(num):
    if i % 2 != 0:
        print(stringa[i])

print(stringa[1::2]) # stampa i caratteri dispari
