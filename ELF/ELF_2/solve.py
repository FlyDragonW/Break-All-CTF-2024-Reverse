from z3 import *

solver = Solver()

x = IntVector('x', 11)

solver.add(x[1] * x[4] * x[3] == 1368252)
solver.add(x[8] + x[8] * x[2] == 11956)
solver.add(x[4] - x[1] - x[3] == -88)
solver.add(x[0] + x[3] + x[4] == 328)
solver.add(x[10] + x[4] - x[5] == 66)
solver.add(x[3] * x[9] + x[4] == 5376)
solver.add(x[1] + x[7] * x[2] == 4279)
solver.add(x[2] * x[10] * x[3] == 379658)
solver.add(x[2] * x[1] * x[6] == 995220)
solver.add(x[4] + x[8] + x[10] == 283)
solver.add(x[1] * x[7] - x[7] == 4601)
solver.add(x[5] - x[8] - x[8] == -149)
solver.add(x[10] * x[9] * x[10] == 73644)
solver.add(x[4] - x[2] - x[2] == -71)
solver.add(x[9] - x[0] + x[2] == 46)
solver.add(x[9] - x[10] * x[10] == -1393)
solver.add(x[0] * x[3] - x[8] == 10384)
solver.add(x[10] - x[4] * x[4] == -15091)
solver.add(x[4] * x[4] * x[9] == 771579)
solver.add(x[1] * x[7] * x[6] == 441180)

flag = ""
if solver.check() == sat:
    model = solver.model()
    print("Solution:")
    for i in range(11):
        print(f"x[{i}] = {model[x[i]]}")
        flag += chr(model[x[i]].as_long())
else:
    print("No solution exists")

print(flag)