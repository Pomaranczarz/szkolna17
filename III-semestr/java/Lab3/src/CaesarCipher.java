public class CaesarCipher {
    public static String encrypt(String message, int offset) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < message.length(); ++i)
            result.append(getEncryptedCharacter(message.charAt(i), offset));

        return result.toString();
    }

    public static String decrypt(String message, int offset) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < message.length(); ++i)
            result.append(getDecryptedCharacter(message.charAt(i), offset));

        return result.toString();
    }

    private static char getEncryptedCharacter(char c, int offset) {
        if (!Character.isLetter(c))
            return c;

        char result;
        if (Character.isUpperCase(c)) {
            if (c + offset > 'Z')
                result = (char)('A' + (c + offset) - 'Z');
            else if (c + offset < 'A')
                result = (char)('Z' - (c + offset) + 'A');
            else
                result = (char)(c + offset);
        }
        else {
            if (c + offset > 'z')
                result = (char)('a' + (c + offset) - 'z');
            else if (c + offset < 'a')
                result = (char)('z' - (c + offset) + 'a');
            else
                result = (char)(c + offset);
        }

        return result;
    }

    private static char getDecryptedCharacter(char c, int offset) {
        if (!Character.isLetter(c))
            return c;

        char result;
        if (Character.isUpperCase(c)) {
            if (c - offset > 'Z')
                result = (char)('A' + (c - offset) - 'Z');
            else if (c - offset < 'A')
                result = (char)('Z' - (c - offset) + 'A');
            else
                result = (char)(c - offset);
        }
        else {
            if (c - offset > 'z')
                result = (char)('a' + (c - offset) - 'z');
            else if (c + offset < 'a')
                result = (char)('z' - (c - offset) + 'a');
            else
                result = (char)(c - offset);
        }

        return result;
    }
}
