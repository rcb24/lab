#include <iostream>
#include <cmath>
#include <cstdlib>
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
void generate_keys(long long &n, long long &e, long long &d)
{
    // Two prime numbers (for simplicity, small primes are used)
    long long p = 61; // Example prime 1
    long long q = 53; // Example prime 2
    n = p * q;
    long long phi = (p - 1) * (q - 1);
    // Find e such that 1 < e < phi and gcd(e, phi) == 1
    e = 3;
    while (gcd(e, phi) != 1)
    {
        e++;
    }
    // Find d such that (d * e) % phi == 1
    d = 1;
    while ((d * e) % phi != 1)
    {
        d++;
    }
}
int main()
{
    long long n, e, d;
    generate_keys(n, e, d);
    std::cout << "Public Key: (n = " << n << ", e = " << e << ")"
              << std::endl;
    std::cout << "Private Key: (n = " << n << ", d = " << d << ")"
              << std::endl;
    // Input message
    long long message;
    std::cout << "Enter the message (numeric) to encrypt: ";
    std::cin >> message;
    // Encryption
    long long encrypted_message = mod_exp(message, e, n);
    std::cout << "Encrypted Message: " << encrypted_message << std::endl;

long long decrypted_message = mod_exp(encrypted_message, d, n);
std::cout << "Decrypted Message: " << decrypted_message << std::endl;
return 0;
}
