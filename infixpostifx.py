def infix_to_postfix(expression: str) -> str:
    """
    Convert an infix expression (with space-separated tokens) to a postfix expression.

    Args:
        expression (str): The infix expression as a string.
                          Example: "A * ( B + C )"

    Returns:
        str: The postfix expression as a string.
             Example: "A B C + *"
    """
    # Hashmap (dictionary) for operator precedence
    precedence = {
        '^': 3,
        '*': 2,
        '/': 2,
        '+': 1,
        '-': 1
    }
    
    # The stack to hold operators
    op_stack = []
    # List for the output tokens
    output = []
    
    # Tokenize the input expression (assumes tokens are space-separated)
    tokens = expression.split()
    
    for token in tokens:
        # If the token is an operand (number or variable), add it to the output
        if token.isalnum():
            output.append(token)
        # If the token is a left parenthesis, push it onto the stack
        elif token == '(':
            op_stack.append(token)
        # If the token is a right parenthesis, pop from the stack until a left parenthesis is found
        elif token == ')':
            while op_stack and op_stack[-1] != '(':
                output.append(op_stack.pop())
            if not op_stack:
                raise ValueError("Mismatched parentheses encountered")
            op_stack.pop()  # Discard the '(' from the stack
        # If the token is an operator
        elif token in precedence:
            # While there's an operator at the top of the stack with greater or equal precedence, pop it
            while (op_stack and op_stack[-1] != '(' and 
                   precedence.get(op_stack[-1], 0) >= precedence[token]):
                output.append(op_stack.pop())
            op_stack.append(token)
        else:
            raise ValueError(f"Unknown token: {token}")
    
    # Pop any remaining operators from the stack and append to output
    while op_stack:
        top_token = op_stack.pop()
        if top_token in ('(', ')'):
            raise ValueError("Mismatched parentheses encountered")
        output.append(top_token)
    
    # Join the output tokens into a string and return
    return ' '.join(output)

def main():
    print("Infix to Postfix Converter using Stack and Hashmap")
    print("Enter an infix expression with tokens separated by spaces (e.g., A * ( B + C ))")
    
    # Read input from the user
    infix_expr = input("Infix Expression: ")
    
    try:
        postfix_expr = infix_to_postfix(infix_expr)
        print("Postfix Expression:", postfix_expr)
    except ValueError as e:
        print("Error:", e)

if __name__ == "__main__":
    main()
