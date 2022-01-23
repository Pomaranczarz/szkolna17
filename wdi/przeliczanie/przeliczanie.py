def get_decimal_value(c):
    return ord(c) - ord('0') if c.isdigit() else ord(c) - ord('A') + 10


def get_character_from_value(i):
    return chr( i + ord('0') ) if i >= 0 and i <= 9 else chr( i + ord('A') - 10 )
    

def convert_to_decimal(value, base):
    if base == 10:
        return value

    result = 0
    for i in range(len(value)):
        result += get_decimal_value(value[::-1][i]) * base**i

    return result


def convert_from_decimal(value, base):
    result = ""
    while value > 0:
        result += get_character_from_value(value % base)
        value //= base

    return result[::-1]


def convert(value, baseFrom, baseTo):
    decimal_value = convert_to_decimal(value, baseFrom)
    return convert_to_decimal(decimal_value, baseTo)


print(convert_from_decimal(convert_to_decimal("112", 8), 8))