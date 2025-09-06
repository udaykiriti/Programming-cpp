# calculator.py
def add(a, b):
    if not isinstance(a, (int, float)) or not isinstance(b, (int, float)):
        raise ValueError("Inputs must be numbers")
    return a + b


def subtract(a, b):
    return a - b
