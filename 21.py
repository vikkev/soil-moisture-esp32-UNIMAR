soma=0
while True:
    print("Digite o algoritimo para calcular (+,*,-,/ ou # para cancelar): ")
    calc = str(input(""))
    if calc=="#":
        break
    n1 = float(input("Digite numero 1: "))
    n2 = float(input("Digite numero 2: "))
    if calc== "+":
        s1=n1+n2
        soma+=s1
    elif calc== "*":
        s2 =n1*n2
        soma += s2
    elif calc == "-":
        s3=n1-n2
        soma+=s3
    elif calc== "/":
        s4 =n1/n2
        soma+=s4
    else:
        print("Valor inválido")

print("O total será: ",soma)