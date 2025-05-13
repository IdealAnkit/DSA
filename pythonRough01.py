def calculate_area(shape, **kwargs):
    """
    Calculates the area of different geometric shapes.

    Args:
        shape (str): The name of the shape ('rectangle', 'circle', or 'triangle').
        **kwargs: Keyword arguments specifying the dimensions of the shape.
            - For 'rectangle': 'length' and 'width' are required.
            - For 'circle': 'radius' is required.
            - For 'triangle': 'base' and 'height' are required.

    Returns:
        float: The area of the shape.

    Raises:
        ValueError: If the shape is invalid or the required dimensions are missing.
    """
    shape = shape.lower()  # Convert shape to lowercase for case-insensitivity

    if shape == 'rectangle':
        length = kwargs.get('length')
        width = kwargs.get('width')
        if length is None or width is None:
            raise ValueError("For a rectangle, both 'length' and 'width' must be provided.")
        if not (isinstance(length, (int, float)) and isinstance(width, (int, float))):
            raise ValueError("Length and width must be numbers.")
        if length < 0 or width < 0:
            raise ValueError("Length and width must be non-negative.")
        return length * width
    elif shape == 'circle':
        radius = kwargs.get('radius')
        if radius is None:
            raise ValueError("For a circle, 'radius' must be provided.")
        if not isinstance(radius, (int, float)):
            raise ValueError("Radius must be a number.")
        if radius < 0:
            raise ValueError("Radius must be non-negative.")
        import math  # Import the math module
        return math.pi * radius * radius  # Use math.pi for accurate Pi
    elif shape == 'triangle':
        base = kwargs.get('base')
        height = kwargs.get('height')
        if base is None or height is None:
            raise ValueError("For a triangle, both 'base' and 'height' must be provided.")
        if not (isinstance(base, (int, float)) and isinstance(height, (int, float))):
             raise ValueError("Base and height must be numbers.")
        if base < 0 or height < 0:
            raise ValueError("Base and height must be non-negative.")
        return 0.5 * base * height
    else:
        raise ValueError(f"Invalid shape: '{shape}'.  Supported shapes are 'rectangle', 'circle', and 'triangle'.")

def main():
    """
    Main function to demonstrate the calculate_area function.
    """
    # Test cases for different shapes
    try:
        rectangle_area = calculate_area('rectangle', length=5, width=10)
        print(f"Area of the rectangle: {rectangle_area}")  # Output: 50

        circle_area = calculate_area('Circle', radius=3)  # Test case-insensitivity
        print(f"Area of the circle: {circle_area:.2f}")  # Output: 28.27 (approximately)

        triangle_area = calculate_area('TRIANGLE', base=6, height=8) # Test case-insensitivity
        print(f"Area of the triangle: {triangle_area}")  # Output: 24.0

        # Example of raising a ValueError due to invalid shape
        # invalid_area = calculate_area('invalid', length=5, width=10) # uncomment to test

        # Example of raising a ValueError due to missing dimensions
        # missing_dimension_area = calculate_area('rectangle', length=5) # uncomment to test

        # Example of negative dimension
        # negative_dimension_area = calculate_area('rectangle', length=-5, width=10) # uncomment to test

        # Example of invalid type
        # invalid_type_area = calculate_area('rectangle', length="abc", width=10) # uncomment to test

    except ValueError as e:
        print(f"Error: {e}")  # Print the error message


if __name__ == "__main__":
    main()  # Call the main function to execute the code
