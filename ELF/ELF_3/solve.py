import sys

import pwn
import angr
import claripy


def main():
    constraints = []
    add_constraints_and_run(constraints)

def add_constraints_and_run(constraints):
    path_to_binary = "./ELF_3"
    filename = "flag.txt"  # :string
    symbolic_file_size_bytes = 19

    project = angr.Project(path_to_binary)

    password = claripy.BVS("", symbolic_file_size_bytes * 8)
    password_file = angr.storage.file.SimFile(
        name=filename,
        content=password,
        size=symbolic_file_size_bytes,
        has_end=True,
    )
    symbolic_filesystem = {filename: password_file}

    initial_state = project.factory.entry_state(
        fs=symbolic_filesystem,
        add_options={
            angr.options.SYMBOL_FILL_UNCONSTRAINED_MEMORY,
            angr.options.SYMBOL_FILL_UNCONSTRAINED_REGISTERS,
        },
    )

    for byte in password.chop(8):
        #initial_state.add_constraints(byte != 0x00)
        initial_state.add_constraints(byte >= 0x30)
        initial_state.add_constraints(byte <= 0x7E)
        
    #initial_state.add_constraints(password[8:0] == ord('f'))
    #initial_state.add_constraints(password[16:8] == ord('l'))
    #initial_state.add_constraints(password[24:16] == ord('a'))
    #initial_state.add_constraints(password[32:16] == ord('g'))
    #initial_state.add_constraints(password[8:0] == ord('}'))

    for constraint in constraints:
        constraint_value = claripy.BVV(constraint, len(constraint) * 8)
        initial_state.add_constraints(password != constraint_value) 


    simulation = project.factory.simgr(initial_state)
    simulation.explore(find=is_successful, avoid=should_abort)

    if simulation.found:
        print("Solution found!")
        solution_state = simulation.found[0]
        solution = solution_state.solver.eval(password, cast_to=bytes)
        constraints.append(solution)
        print(f"Flag: {solution}")
        add_constraints_and_run(constraints)

    else:
        raise Exception("Could not find the solution")

def is_successful(state):
    stdout_output = state.posix.dumps(sys.stdout.fileno())
    return b"Correct" in stdout_output


def should_abort(state):
    stdout_output = state.posix.dumps(sys.stdout.fileno())
    return b"Wrong" in stdout_output


if __name__ == "__main__":
    main()