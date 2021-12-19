class ratio:
    def __init__(self, numerator, denominator):
        if not isinstance(numerator, int) or not isinstance(denominator, int):
            raise ValueError("Numerator and denominator have to be int")
        
        self.numerator = numerator
        self.denominator = denominator


    def from_int(number):
        if not isinstance(number, int):
            raise ValueError("Numerator and denominator have to be int")
        
        return ratio(number, 1)


    def from_str(s):
        number = int(s)
        return ratio.from_int(number)

    
    def gcd(a, b):
        while b != 0:
            rem = a % b
            a = b
            b = rem

        return a


    def simplify(self):
        gcd = ratio.gcd(self.numerator, self.denominator)
        
        return ratio(self.numerator // gcd, self.denominator // gcd)


    def expand(self, new_denominator):
        mul = new_denominator // self.denominator
        
        return ratio(self.numerator * mul, new_denominator)


    def get_common_denominator(self, other):
        return (self.denominator * other.denominator) // ratio.gcd(self.denominator, other.denominator)


    def __add__(self, other):
        if isinstance(other, int):
            other = ratio(other, 1)

        common_denominator = self.get_common_denominator(other)
        selfExtended = self.expand(common_denominator)
        otherExtended = other.expand(common_denominator)

        return ratio(selfExtended.numerator + otherExtended.numerator, common_denominator)


    def __sub__(self, other):
        if isinstance(other, int):
            other = ratio(other, 1)

        common_denominator = self.get_common_denominator(other)
        selfExtended = self.expand(common_denominator)
        otherExtended = other.expand(common_denominator)

        return ratio(selfExtended.numerator - otherExtended.numerator, common_denominator)


    def __mul__(self, other):
        if isinstance(other, int):
            other = ratio(other, 1)

        return ratio(self.numerator * other.numerator, self.denominator * other.denominator)
    

    def __truediv__(self, other):
        if isinstance(other, int):
            other = ratio(other, 1)

        return ratio(self.numerator * other.denominator, self.denominator * other.numerator)


    def __str__(self):
        return f'( { self.numerator } / { self.denominator } )'
