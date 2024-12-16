import itertools

def calc(p_list):
    password = 0
    for i in range(len(p_list)):
        if(i % 2 == 0): password += p_list[i]
        elif(i % 3 == 0): password *= p_list[i]
        elif(i % 5 == 0): password -= p_list[i]
        else: password = (password - p_list[i])*2
    return password
		

array = list(range(10))

permutations = itertools.permutations(array, len(array))

for p in permutations:
    if(calc(list(p)) == 3000): print(p)
    #print(calc(list(p)))